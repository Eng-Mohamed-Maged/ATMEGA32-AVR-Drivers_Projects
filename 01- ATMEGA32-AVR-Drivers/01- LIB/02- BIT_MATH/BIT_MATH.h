/*******************************************************/
/* Author    :  Mohamed Maged                          */
/* Date      :  2 October 2023                         */
/* Version   :  V02                                    */
/* LOG       :  V01  -> Initial Creation               */
/*              V02  -> Fix Errors                     */
/*******************************************************/
 #ifndef BIT_MATH_H
 #define BIT_MATH_H
 
 #define SET_BIT(VAR,BIT)    (VAR |=  (1 <<BIT))
 #define CLR_BIT(VAR,BIT)    (VAR &= ~(1 << BIT))
 #define GET_BIT(VAR,BIT)   ((VAR >>BIT) & 1)
 #define TOG_BIT(VAR,BIT)   (VAR ^=  (1 <<BIT))

#endif
