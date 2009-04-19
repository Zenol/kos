/*
** kern.c for kos in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sun Dec 21 01:04:39 2008 jeremy cochoy
** Last update Sun Apr 19 21:47:40 2009 jeremy cochoy
*/

#include "klib.h"
#include "sysio.h"

int	main(void);

void	_start(void)
{
  main();
}

int	main(void)
{
  tty_y = 2;

  //Clear screen
  clear();

  //Load GDT
  setColor(RED, FALSE, BLACK, 0);
  print("Kernel : loading gdt\t\n");

  gdt_reload();

  /* Refresh Stack Ptr */
  asm("movw $0x18, %ax     \n \
       movw %ax, %ss       \n \
       movl $0x1FFF0, %esp \n");
  print("Kernel : gdt loaded\n");

  //Load IDT
  setColor(YELLOW, FALSE, BLACK, 0);
  print("Kernel : loading idt\t\n");

  //Kernel OK
  setColor(PURPLE, FALSE, BLACK, 0);
  print("\n\nKernel : kernel loaded\n");

  while(42);
}
