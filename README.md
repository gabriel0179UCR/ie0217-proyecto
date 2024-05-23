# Información teórica


## Aspectos generales del proyecto

### Título: Sistema de gestión bancaria

#### Resumen de requisitos

Cliente objetivo: Agentes que atienden clientes en un banco.

1.	Modalidad de operación: El sistema inicia con dos opciones; modalidad de atención a clientes, obtener información sobre préstamos.
2.	Información general: Opciones; 
    -	Préstamos personales, prendarios, hipotecarios. 
    -	Generar una tabla de pagos para la opción elegida, el monto del préstamo es ingresado por el usuario. 
    -	Obtener la tabla mediante valores personalizados de monto, cantidad de cuotas y la tasa de interés.
3.	Cuentas bancarias: Un cliente posee dos cuentas; colones y dólares.
4.	Operaciones disponibles: Operaciones; depósitos, retiros, transferencias, abonos a préstamos.
5.	Registro de transacciones: Registro detallado de todas las transacciones realizadas.
6.	Identificación de clientes: Único para cada cliente. Entre 0 y 999999999.
7.	Préstamos asociados: Préstamos asociados, en colones o dólares. Características; tasa de interés, periodo en meses y la cuota mensual.
8.	Reporte de préstamos: El cliente puede solicitar un reporte de sus préstamos. Se genera un archivo de texto que detalla las cuotas pagadas, desglosando el reporte al capital y los intereses abonados hasta el momento.
9.	Almacenamiento de la información: Uso de base de datos SQL.

#### Diagramas generales

Diagramas de las dos principales opciones del programa; atención a clientes y obtener información general.

<img src="Images/AtencionClientes.png" alt="AtencionClientes" width="500"/>

<img src="Images/InfoGeneral.png" alt="InfoGeneral" width="500"/>