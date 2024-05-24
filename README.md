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


#### Informacion teorica

- ¿Para que sirve un sistema de gestion bancaria?
Un sistema de gestion bancaria permite el manejo de la informacion y solicitudes por lo clientes de forma mas controlada y manteniendo un registro de todos los movimientos.

- ¿Que es un prestamo personal, prendario e hipotecario?
Un prestamo personal es un movimiento financiero en el cual el prestamista (el emisor) entrega una cantidad de dinero al prestatario (el receptor).

Un prestamo prendario es un movimiento igual al de un prestamo personal, pero con la condicion que el prestatario debe brindar uno o varios activos fisicos o financieros como garantia que equivalen a la cantidad del prestamo.

Un prestamos hipotecario es un movimiento igual al de un prestamo personal, pero orientado a la prestacion de dinero para la compra de un inmueble. Este movimiento requiere de la devolucion del dinero en pagos mensuales y con intereses.

- ¿Que son cuotas y tasas de interes?

Las cuotas son un monto periodico en el que una persona paga periodicamente para pagar una deuda, por ejemplo pagos mensuales de un prestamo hipotecario.

Las tasas de interes son un porcentaje de operaciones que se realizan con el dinero. Existen dos tipos; interes por deposito, interes por credito. La tasa de interes por deposito equivale al pago que recibe una persona que deposita el dinero en disposicion de otra persona o entidad, por ejemplo las cuentas de ahorros. La tasa de interes por credito equivale al monto que debe pagar una persona a otra persona o entidad por la prestacion de dinero, por ejemplo los prestamos hipotecarios.

- ¿Que es una cuenta que gestiona ahorros?
Una cuenta que gestiona ahorros es una cuenta que brinda una tasa de interes alta. La condicion para el uso de una cuenta de ahorros es el de ingresar un monto de dinero que no se puede retirar si se quiere obtener la tasa de interes. En caso de retirar el monto antes del periodo de tiempo definido, no se obtendra la tasa de interes.

- ¿Que es un certificado de deposito a plazo?
Un certificado de deposito a plazo es un tipo de inversion que permite invertir una cantidad de dinero por un periodo de tiempo para obtener un retorno respecto a una tasa de interes alta. Durante este periodo de tiempo no se puede retirar el monto. En caso de entraer el monto, no se obtendra la tasa de interes.

- ¿Que es un deposito, retiro, transferencia, abonos?
Un deposito es un movimiento financiero en el que se envia dinero fisico a una cuenta bancaria.

Un retiro es un movimiento financiero en el que se extraer dinero fisico de una cuenta bancaria.

Una transferencia es un movimiento financiero en el que envia dinero de una cuenta bancaria a otra.

Los abonos es el dinero que se envia como parte de un pago por un bien o servicio.

- ¿Que es una transaccion?

Una transaccion es el flujo financiero reflecado como la creacion, transformacion, intercambio, transferencia o extincion de un valor economico.

- ¿Que es un reporte de prestamos? ¿Que son aporte al capital y los intereses abonados?
Un reporte de prestamos o historiual crediticio es un listado de todos los prestamos y abonos a prestamos de un cliente.

El aporte al capital es el abono que se realiza en un prestamo para la reduccion de la deuda.

Los intereses abonados es el abono que se realiza en un prestamo para la reduccion de la tasa de interes generada de la deuda.

