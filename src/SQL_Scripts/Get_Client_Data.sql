/*
Get Client Data

Query que solicita la informacion basica de un usuario en la base de datos. Cuentas.

Parametros:
- {0}: ID del cliente
*/


SELECT 
    C.ID "ID del Cliente"
    ,C.Nombre "Nombre del cliente"
    ,Cu.ID "ID de la cuenta"
    ,D.Denominacion "Denominacion"
    ,Cu.Cantidad "Cantidad"
    ,Cu.FechaCreacion "Fecha de creacion"
FROM Clientes C
LEFT JOIN Cuentas Cu ON Cu.ClientesID = C.ID
LEFT JOIN Denominaciones D ON D.ID = Cu.DenominacionID
WHERE C.ID = {0};