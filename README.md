# bruteforce-detector

> Estado: en desarrollo

Detector de ataques de fuerza bruta
por SSH, escrito en C++.

## Qué hace

Lee un archivo de log de SSH
(`auth.log`) y detecta las IPs que
intentaron entrar muchas veces sin
éxito en poco tiempo. Además avisa
si alguna de esas IPs logró entrar
después de los intentos fallidos.

## Cómo detecta un ataque

Una IP se marca como sospechosa si
tiene **5 o más intentos fallidos
dentro de un tiempo de 10 minutos**.

Ambos valores se pueden cambiar
al ejecutar el programa.

Si una IP sospechosa tiene un login
exitoso posterior, se marca como
**posible compromiso**.

## Entrada

Un archivo de log de SSH en formato
estándar de Linux
(`/var/log/auth.log`).

El programa usa estas líneas:

- `Failed password for ...`
- `Accepted password for ...`

El resto de las líneas se ignora.

## Salida

Ejemplo:

```
IPs sospechosas
(umbral: 5 fallos en 10 min)

203.0.113.5
  Intentos fallidos: 23
  Primer intento: Nov 18 14:32:01
  Último intento: Nov 18 14:39:47
  Usuarios probados: root, admin
  ALERTA: login exitoso posterior
    Nov 18 14:41:02 (usuario: admin)

Total: 1 IP sospechosa
```

## Cómo compilar y usar

Compilar:

```
g++ -std=c++17 -Wall -o bruteforce-detector src/main.cpp
```

Usar con valores por defecto:

```
./bruteforce-detector auth.log
```

Cambiar umbral y ventana:

```
./bruteforce-detector auth.log 3 5
```

(3 fallos en 5 minutos)

## Limitaciones conocidas

- Solo soporta el formato de log
  de SSH en Linux.
- Las fechas de `auth.log` no
  incluyen el año, así que se asume
  que todo el log es del mismo año.

## Próximas mejoras

- Soporte para logs de Apache y nginx.
- Salida en formato JSON.
- Tests automáticos.