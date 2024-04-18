# Computación en GPU

## Tarea 1



### Preguntas

 - Utilizar integer en vez de double afectará la exactitud de la matriz, ya que en este caso los números tendran una representación exacta, a diferencia de la utilizada por los double.
 - La precisión disminuirá en cuanto mas alejados de 0 estén los números de la matriz, ya que hay una menor densidad de números representables para aproximarlos.
 - Sí. Dado que los numeros de punto flotante son inexactos, sería imposible distinguir con seguridad entre un número de punto flotante muy cercano a un cierto entero por inexactitud, o porque su valor real es efectivamente distinto al del entero.
   
    Por ejemplo: al comparar  2.005 y 2, no existe un método que permita saber si la diferencia entre ellos es debido a la inexactitud del formato o a una diferencia legítima del cómputo.


