/*
Transactions

Query que consulta el reporte de transacciones

Parametros:
- {0}: ID del cliente
*/

SELECT 
    T.Fecha "Fecha"
    T.ClienteID "ID del Cliente"
	,C.Nombre "Cliente"
    ,TT.Transaccion "Transaccion"
    ,T.CuentaFuenteID "Cuenta Fuente"
    ,T.CuentaDestinoID "Cuenta Destino"
    ,D.Denominacion "Denominacion"
    ,T.CantidadPrevio "Cantidad Previo"
    ,T.CantidadPosterior "Cantidad Antes"
    ,T.Diferencia "Diferencia"
FROM 
Transacciones T
LEFT JOIN Clientes C ON C.ID = T.ClienteID
LEFT JOIN TipoTransaccion TT ON TT.ID = T.TipoTransaccionID
LEFT JOIN Denominaciones D ON D.ID = T.DenominacionID
WHERE T.ClienteID = {0};