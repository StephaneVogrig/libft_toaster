#!/bin/bash

while true; do
  clear
  
  norminette ../libft/*.c ../libft/*.h | grep -v 'OK'

  make -C ../libft
  make

  sleep 5
done

