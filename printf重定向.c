extern UART_HandleTypeDef huart1;   //声明串口
		
	/**
      * @brief  重定向c库函数printf到DEBUG_USARTx
      * @note   
      * @param  
      * @retval 
      */	
		
		int fputc(int ch, FILE*f)
		{
		  HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1,0xffff);
		  return ch;
		
		}
		
		/**
      * @brief  重定向c库函数getchar,scanf到DEBUG_USARTx

      * @note   
      * @param  
      * @retval 
      */
		
		int fgetc(FILE *f)
		{
			uint8_t ch = 0;
			HAL_UART_Receive(&huart1, &ch, 1, 0xffff);
			return ch;
		}
