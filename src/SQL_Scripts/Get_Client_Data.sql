/*
Get Client Data

Query que solicita la informacion basica de un usuario en la base de datos. Cuentas.

Parametros:
- {0}: ID del cliente
*/


SELECT 
    C.ID
    ,C.Nombre
    ,Cu.ID
    ,D.Denominacion
    ,Cu.Cantidad
    ,Cu.FechaCreacion 
FROM Clientes C
LEFT JOIN Cuentas Cu ON Cu.ClientesID = C.ID
LEFT JOIN Denominaciones D ON D.ID = Cu.DenominacionID
WHERE C.ID = {0};