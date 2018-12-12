# Tono Noche de Paz con Arduino

El objetivo de esta práctica es reproducir con ayuda de un zumbador (buzzer) el tono de Noche de Paz.


www.insani-loja.com

| Autor de la práctica |
| Juan Andrés (INSANI) |


## Materiales
- Placa Vennom V2.
- Cable USB - miniUSB

![Placa de programacion Vennom](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/placa-version2.png)

*En caso de no tener placa Vennom los materiales son:*
- 1 Arduino
- 1 Protoboard
- 1 Zumbador o Buzzer


## Esquema eléctrico
Se conecta el cable negro (negativo) del zumbador o buzzer al pin GND de la placa de arduino y el cable rojo (positivo) al pin PWM 11 de la placa de arduino.

![Esquema de conexion ](https://github.com/jandrs300/Bloques_M/blob/master/ejemplos_vennom/Version_2/Guerra_Galaxias_buzzer/guerra_galaxias_f.png)



## Programación en MBLOCK
Al ejecutar el código que vemos a continuación tendremos el resultado de la práctica.


![programa en mblock tono noche de paz con Arduino1](https://github.com/Insani01/Tutoriales/blob/master/BUZZER/Buzzer_Noche_paz/Noche_paz1.png)
![programa en mblock tono noche de paz con Arduino2](https://github.com/Insani01/Tutoriales/blob/master/BUZZER/Buzzer_Noche_paz/Noche_paz2.png)


## Simulación
Para la simulación utilizamos un arduino UNO, es **igual** al arduino nano, la única diferencia es el tamaño, los pines y demás son los mismos.

A continuación podremos ver la simulación del programa realizado.  [Clic para ver la simulación](  https://www.tinkercad.com/things/lkuEZxmn3yK  )


 
## Programación en Arduino
- Primero declaramos los pines 11 como salida.
- La funcion **tone** *genera una onda cuadrada de la frecuencia especificada* en un pin, debemos especificar la duración. Para más información [función tone()](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/)




```


void setup(){
    pinMode(11,OUTPUT);
    tone(11,392,500); // write to buzzer
    delay(500);
    tone(11,440,250); // write to buzzer
    delay(250);
    tone(11,392,500); // write to buzzer
    delay(500);
    tone(11,330,1000); // write to buzzer
    delay(1000);
    tone(11,392,500); // write to buzzer
    delay(500);
    tone(11,440,250); // write to buzzer
    delay(250);
    tone(11,392,500); // write to buzzer
    delay(500);
    tone(11,330,1000); // write to buzzer
    delay(1000);
    tone(11,587,1000); // write to buzzer
    delay(1000);
    tone(11,587,500); // write to buzzer
    delay(500);
    tone(11,494,1000); // write to buzzer
    delay(1000);
    tone(11,523,1000); // write to buzzer
    delay(1000);
    tone(11,523,500); // write to buzzer
    delay(500);
    tone(11,392,1000); // write to buzzer
    delay(1000);
    tone(11,440,1000); // write to buzzer
    delay(1000);
    tone(11,440,500); // write to buzzer
    delay(500);
    tone(11,523,500); // write to buzzer
    delay(500);
    tone(11,494,250); // write to buzzer
    delay(250);
    tone(11,440,500); // write to buzzer
    delay(500);
    tone(11,392,500); // write to buzzer
    delay(500);
    tone(11,440,250); // write to buzzer
    delay(250);
    tone(11,392,500); // write to buzzer
    delay(500);
    tone(11,330,1000); // write to buzzer
    delay(1000);
    tone(11,294,1000); // write to buzzer
    delay(1000);
    tone(11,294,500); // write to buzzer
    delay(500);
    tone(11,698,500); // write to buzzer
    delay(500);
    tone(11,587,250); // write to buzzer
    delay(250);
    tone(11,494,500); // write to buzzer
    delay(500);
    tone(11,523,1000); // write to buzzer
    delay(1000);
    tone(11,659,1000); // write to buzzer
    delay(1000);
    tone(11,523,500); // write to buzzer
    delay(500);
    tone(11,392,250); // write to buzzer
    delay(250);
    tone(11,330,500); // write to buzzer
    delay(500);
    tone(11,392,500); // write to buzzer
    delay(500);
    tone(11,349,250); // write to buzzer
    delay(250);
    tone(11,294,500); // write to buzzer
    delay(500);
    tone(11,262,1000); // write to buzzer
    delay(1000);
    
}

void loop(){
    
 
}
```

