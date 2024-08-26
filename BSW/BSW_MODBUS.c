#include "BSW_MODBUS.h"
#include "APP_Parameter.h"
#include "MCAL_RTC.h"
#include "MCAL_UART.h"
#include "apm32e10x_gpio.h"
#include "apm32e10x_misc.h"
#include "apm32e10x_rcm.h"
#include "Ext_led.h"

uart_str uart_modbus = { 0 };

static void MBSResponseError( uint16_t func, uint16_t error );

uint16 Set_Rtcfunc( uint8* val )
{
    uint16   ret   = 0;
    uint16_t year  = val[ 12 ] + 2000;
    uint8_t  month = val[ 11 ];
    uint8_t  date  = val[ 10 ];
    ;
    uint8_t hour = val[ 9 ];
    uint8_t min  = val[ 8 ];
    uint8_t sec  = val[ 7 ];
    rtc_set( year, month, date, hour, min, sec );
    return ret;
}

void MBSReadRegsRequst( uint16_t startAddr, uint16_t len, uint8_t func )
{
    uint16_t i   = 0;
    uint16_t crc = 0;
    uint16   ptr;

    uint8_t tx[ 256 ] = { 0 };
    tx[ i++ ]         = app_parameter_read_Module_address( );
    tx[ i++ ]         = func;
    if ( func != FUNC_CODE_18 )
    {
        if ( func == FUNC_CODE_10 )
        {
            tx[ i++ ] = 1;
            tx[ i++ ] = 0x01; /* default set time OK */
        }
        else
        {
            tx[ i++ ] = len * 2;
            for ( uint16_t j = startAddr; j < startAddr + len; ++j )
            {
                if ( func == FUNC_CODE_1 )
                {
                    ptr = bsw_modbus_list[ 0 ].read_callbcak( j );
                }
                else if ( func == FUNC_CODE_2 )
                {
                    ptr = bsw_modbus_list[ 1 ].read_callbcak( j );
                }
                else if ( func == FUNC_CODE_3 )
                {
                    ptr = bsw_modbus_list[ 2 ].read_callbcak( j );
                }
                tx[ i++ ] = (uint8)( ptr >> 8 );
                tx[ i++ ] = (uint8)( ptr );
            }
        }
    }
    else
    {
        uint16                   soe_len = 0;
        App_scroll_storage_datas soe_datas;
        uint16                   memory_number = 0;
        uint16                   soe_page      = ( len - 1 ) * 8; /* group:0 ~ 31,page: 0 ~ 255 */
        uint8                    ret           = E_NOK;
        ret                                    = APP_Scroll_read_memory_number( Controls_block, &memory_number ); /* Determine whether SOE has data */
        if ( ret == E_OK )
        {
            if ( memory_number == 0 )
            {
                soe_len   = 1;
                tx[ i++ ] = (uint8)( soe_len );
                tx[ i++ ] = 0; /* SOE datas is NULL */
            }
            else
            {
                /* Multiply the number of read SOE by 12 */
                soe_len   = 8 * ONE_STORE_SIZE;
                tx[ i++ ] = (uint8)( soe_len );

                for ( uint16_t j = soe_page; j < soe_page + 8; j++ )
                {
                    ret = APP_Scroll_storage_read( Controls_block, j, &soe_datas );
                    if ( ret == E_OK )
                    {
                        memcpy( tx + i, &soe_datas, sizeof( App_scroll_storage_datas ) );
                        i += ONE_STORE_SIZE;
                    }
                    else
                    {
                        MBSResponseError( func, Slave_Device_Failure );
                        return;
                    }
                }
            }
        }
        else
        {
            MBSResponseError( func, Slave_Device_Failure );
            return;
        }
    }

    crc       = CRC16( tx, i );
    tx[ i++ ] = (uint8_t)( crc >> 8 );
    tx[ i++ ] = (uint8_t)crc;
    MODBUS_SendData( &tx[ 0 ], i );
}

void MBSWriteRegsRequst( uint16_t startAddr, uint16_t cmd, uint8_t func )
{
    uint8_t  tx[ 32 ] = { 0 };
    uint16_t i        = 0;
    uint16_t crc      = 0;

    tx[ i++ ]         = app_parameter_read_Module_address( );
    tx[ i++ ]         = func;
    tx[ i++ ]         = (uint8_t)( startAddr >> 8 );
    tx[ i++ ]         = (uint8_t)( startAddr );
    if ( func == FUNC_CODE_5 )
    {
        bsw_modbus_list[ 2 ].write_callbcak( startAddr, cmd );
    }

    tx[ i++ ] = (uint8_t)( cmd >> 8 );
    tx[ i++ ] = (uint8_t)( cmd );
    crc       = CRC16( tx, i );
    tx[ i++ ] = (uint8_t)( crc >> 8 );
    tx[ i++ ] = (uint8_t)crc;

    MODBUS_SendData( &tx[ 0 ], i );
}

void MBSWriteMultiRegsRequst( uint16_t startAddr, uint16_t len, uint8_t func, uint8_t* data )
{
    uint8_t  tx[ 256 ] = { 0 };
    uint16_t i         = 0;
    uint16_t crc       = 0;

    tx[ i++ ]          = app_parameter_read_Module_address( );
    tx[ i++ ]          = func;
    tx[ i++ ]          = ( startAddr << 8 ) & 0xff;
    tx[ i++ ]          = startAddr & 0xff;
    tx[ i++ ]          = ( len << 8 ) & 0xff;
    tx[ i++ ]          = len & 0xff;

    //    for ( uint16_t j = startAddr, t = 7; j < startAddr + len; ++j )
    //    {

    //    }
    crc                = CRC16( &tx[ 0 ], i );
    tx[ i++ ]          = (uint8_t)( crc >> 8 );
    tx[ i++ ]          = (uint8_t)crc;
    MODBUS_SendData( &tx[ 0 ], i );
}

static void MBSResponseError( uint16_t func, uint16_t error )
{
    uint8_t  tx[ 12 ] = { 0 };
    uint16_t i        = 0;
    uint16_t crc      = 0;

    tx[ i++ ]         = app_parameter_read_Module_address( );
    tx[ i++ ]         = func + 0x80;
    tx[ i++ ]         = error;
    crc               = CRC16( tx, i );
    tx[ i++ ]         = (uint8_t)( crc >> 8 );
    tx[ i++ ]         = (uint8_t)crc;

    MODBUS_SendData( &tx[ 0 ], i );
}

void uart_recv_func( uint8_t* data, uint16_t len )
{
    uint8_t  modbus_head   = 0;
    uint8_t  modbus_cmd    = 0;
    uint16_t modbus_addr   = 0;
    uint16_t my_crc        = 0;
    uint16_t modbus_len    = 0;
    uint16_t recv_crc      = 0;
    uint16_t reg_len       = 0;
    uint16_t control_datas = 0;
    uint16_t soe_group;

    if ( data == NULL || len <= 2 )
    {
        return;
    }

    recv_crc |= data[ len - 2 ] << 8 | data[ len - 1 ];

    modbus_head = data[ 0 ];

    if ( ( app_parameter_read_Module_address( ) != modbus_head ) && ( BOARDCASE_ADDR != modbus_head ) )
    {
        return;
    }

    my_crc      = CRC16( data, len - 2 );

    modbus_addr = data[ 2 ] << 8 | data[ 3 ];
    modbus_cmd  = data[ 1 ];
    if ( my_crc != recv_crc )
    {
        MBSResponseError( modbus_cmd, Memory_Parity_Error );
        return;
    }
    switch ( modbus_cmd )
    {
        case FUNC_CODE_1:
            modbus_len = data[ 4 ] << 8 | data[ 5 ];
            if ( modbus_addr > DI10_ADDRESS )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Address );
                return;
            }
            if ( ( modbus_addr + modbus_len ) > DI10_ADDRESS )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Value );
                return;
            }
            MBSReadRegsRequst( modbus_addr, modbus_len, modbus_cmd );
            break;
        case FUNC_CODE_2:
            modbus_len = data[ 4 ] << 8 | data[ 5 ];
            if ( ( modbus_addr < Voltage_Ua_ADDRESS ) || ( modbus_addr > Fundamental_Freq_ADDRESS ) )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Address );
                return;
            }
            if ( ( modbus_addr + modbus_len ) > Fundamental_Freq_ADDRESS )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Value );
                return;
            }
            MBSReadRegsRequst( modbus_addr, modbus_len, modbus_cmd );
            break;
        case FUNC_CODE_3:
            modbus_len = data[ 4 ] << 8 | data[ 5 ];
            if ( ( modbus_addr < Overvoltage_protection_LV1_One_Value_ADDRESS ) || ( modbus_addr > Restore_time_ADDRESS ) )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Address );
                return;
            }
            if ( ( modbus_addr + modbus_len ) > Restore_time_ADDRESS )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Value );
                return;
            }
            MBSReadRegsRequst( modbus_addr, modbus_len, modbus_cmd );
            break;

        case FUNC_CODE_5:
            control_datas = data[ 4 ] << 8 | data[ 5 ];
            if ( ( modbus_addr & 0X3F00 ) == 0 )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Address );
                return;
            }
            if ( ( control_datas != RELAY_ON ) && ( control_datas != RELAY_OFF ) )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Value );
                return;
            }
            MBSWriteRegsRequst( modbus_addr, control_datas, modbus_cmd );
            break;
        case FUNC_CODE_10: /* No response required */
            reg_len    = data[ 4 ] << 8 | data[ 5 ];
            modbus_len = data[ 6 ];
            if ( modbus_addr != SET_TIME_ADDRESS )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Address );
                return;
            }
            if ( reg_len != 3 )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Value );
                return;
            }
            if ( modbus_len != 6 )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Value );
                return;
            }
            Set_Rtcfunc( data );
            if ( modbus_head != BOARDCASE_ADDR )
            { /* The broadcast address does not respond */
                MBSReadRegsRequst( modbus_addr, reg_len, modbus_cmd );
            }
            break;
        case FUNC_CODE_18:
            soe_group = data[ 4 ] << 8 | data[ 5 ];
            if ( modbus_addr != SOE_REG_ADDRESS )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Address );
                return;
            }
            if ( ( soe_group > 32 ) && ( soe_group == 0 ) )
            {
                MBSResponseError( modbus_cmd, Illegal_Data_Value );
                return;
            }
            MBSReadRegsRequst( modbus_addr, soe_group, modbus_cmd );
            break;
        default:
            MBSResponseError( modbus_cmd, Illegal_Function );
            break;
    }
}

void BSW_ModbusMainfunction( void )
{
    while ( 1 )
    {
        if ( 1 == uart_modbus.recv_flag )
        {
            uart_recv_func( uart_modbus.recv_buff, uart_modbus.recv_len );
            uart_modbus.recv_flag = 0;
            uart_modbus.recv_len  = 0;
            Set_commun_Led( false );
            memset( uart_modbus.recv_buff, 0, USART_DATA_LEN );
        }
        vTaskDelay( 5 );
    }
}

void MODBUS_SendData( uint8_t* data, uint8_t data_len )
{
    xSemaphoreTake( SendMutex, portMAX_DELAY );
    for ( uint16 index = 0; index < data_len; index++ )
    {
        /* Loop until the end of transmission */
        while ( USART_ReadStatusFlag( uartSignalsCfgTable[ 0 ].uart, USART_FLAG_TXBE ) == RESET )
            ;
        USART_TxData( uartSignalsCfgTable[ 0 ].uart, data[ index ] );
    }
    xSemaphoreGive( SendMutex );
}

/**
 * @brief       �����жϷ�����
 * @param       ��
 * @retval      ��
 */
void USART1_IRQHandler( void )
{
    if ( USART_ReadIntFlag( uartSignalsCfgTable[ 0 ].uart, USART_INT_RXBNE ) == SET )
    {
        uart_modbus.recv_buff[ uart_modbus.recv_cnt++ ] = USART_RxData( uartSignalsCfgTable[ 0 ].uart );
        USART_ClearIntFlag( uartSignalsCfgTable[ 0 ].uart, USART_INT_RXBNE );
        Set_commun_Led( true );
        if ( uart_modbus.recv_cnt >= 256 )
        {
            uart_modbus.recv_cnt = 0;
        }
    }

    // �����жϴ���
    if ( USART_ReadStatusFlag( uartSignalsCfgTable[ 0 ].uart, USART_FLAG_IDLE ) != RESET )
    {
        uartSignalsCfgTable[ 0 ].uart->STS;
        uartSignalsCfgTable[ 0 ].uart->DATA;
        uart_modbus.recv_len  = uart_modbus.recv_cnt;
        uart_modbus.recv_cnt  = 0;
        uart_modbus.recv_flag = 1;
    }
}
