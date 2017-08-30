  .syntax unified
  .cpu cortex-m3
  .fpu softvfp
  .thumb

  .global MY_TIM1_UP_IRQHandler
  
  .section .text

 .type MY_TIM1_UP_IRQHandler, %function
MY_TIM1_UP_IRQHandler:
   //Put tcb code here
   push {R4-R11}
   ldr R0, =curTCB
   ldr R0, [R0]

   str SP, [R0,#12]
   str LR, [R0,#24]
   ldr R0, [R0]
   ldr SP, [R0,#12]
   ldr LR, [R0,#24]
   ldr R1 , =curTCB
   str R0, [R1]
 
   pop {R4-R11}
  
   b   TIM1_UP_IRQHandler

