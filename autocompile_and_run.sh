#!/bin/bash

draw_line() {
  echo "--------------------------------------------------------------------------------"
}

while true; do
  clear
  
  draw_line
  
  echo norminette
  norminette ../libft/*.c ../libft/*.h | grep -v 'OK'
  #norminette libft/*.c libft/*.h | grep -v 'OK'
  
  draw_line
  
  echo make libft
  make -C ../libft
  
  #draw_line
  
  echo make libft_test
  make
  
 # draw_line
  
 ./libft_test_stephane
 
  #draw_line
  
  sleep 5
done

