/*
Transfer

Query que actualiza la cantidad de dinero en dos cuentas (transfiere dinero de una cuenta a otra)

Parametros:
- {0}: ID del cliente fuente
- {1}: ID del cliente destino
- {2}: Cantidad de dinero a restar de la cuenta fuente
- {3}: Cantidad de dinero a sumar a la cuenta destino
- {4}: Denominacion de la cuenta fuente
- {5}: Denominacion de la cuenta destino

*/

-- Se actualiza la cantidad en la cuenta fuente
UPDATE Cuentas SET Cantidad = Cantidad + {2} 
WHERE ClientesID = {0} 
    AND DenominacionID = (
        SELECT ID FROM Denominaciones WHERE Denominacion = '{4}'
    );

-- Se actualiza la cantidad en la cuenta destino
UPDATE Cuentas SET Cantidad = Cantidad - {3}
WHERE ClientesID = {1} 
    AND DenominacionID = (
        SELECT ID FROM Denominaciones WHERE Denominacion = '{5}'
    );

-- Se registra la transaccion
INSERT INTO Transacciones(ClienteID, TipoTransaccionID, CuentaFuenteID, CuentaDestinoID, DenominacionID, CantidadPrevio, CantidadPosterior, Diferencia)
VALUES(
	{0},
    (SELECT ID FROM TipoTransaccion WHERE Transaccion = 'Transferencia'),
    (SELECT ID FROM Cuentas WHERE ClientesID = {0} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{4}')),
    (SELECT ID FROM Cuentas WHERE ClientesID = {1} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{5}')),
    (SELECT ID FROM Denominaciones WHERE Denominacion = '{4}'),
    (SELECT Cantidad + {2} FROM Cuentas WHERE ClientesID = {0} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{4}')),
    (SELECT Cantidad FROM Cuentas WHERE ClientesID = {0} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{4}')),
    0-{2}
);

INSERT INTO Transacciones(ClienteID, TipoTransaccionID, CuentaFuenteID, CuentaDestinoID, DenominacionID, CantidadPrevio, CantidadPosterior, Diferencia)
VALUES(
	{1},
    (SELECT ID FROM TipoTransaccion WHERE Transaccion = 'Transferencia'),
    (SELECT ID FROM Cuentas WHERE ClientesID = {0} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{4}')),
    (SELECT ID FROM Cuentas WHERE ClientesID = {1} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{5}')),
    (SELECT ID FROM Denominaciones WHERE Denominacion = '{5}'),
    (SELECT Cantidad - {2} FROM Cuentas WHERE ClientesID = {1} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{5}')),
    (SELECT Cantidad FROM Cuentas WHERE ClientesID = {1} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{5}')),
    {2}
);


SELECT 
    ClienteID "ID del cliente"
    ,CuentaFuenteID "Cuenta fuente"
    ,CuentaDestinoID "Cuenta destino"
    ,D.Denominacion "Denominacion"
    ,CantidadPrevio "Cantidad en cuenta fuente"
    ,Diferencia "Cantidad transferida"
FROM Transacciones T
LEFT JOIN Denominaciones D ON D.ID = T.DenominacionID
WHERE ClienteID = {0}
ORDER BY Fecha LIMIT 1;