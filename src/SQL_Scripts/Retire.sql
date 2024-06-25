/*
Retire

Query que actualiza la cantidad de dinero en una cuenta

Parametros
- {0}: ID del cliente
- {1}: Denominacion (ej. 'Colones')
- {2}: Cantidad
*/

-- Se actualiza la fila en la tabla Cuentas
UPDATE Cuentas SET Cantidad = Cantidad - {2} WHERE ClientesID = {0} AND DenominacionID = (
    SELECT ID AS DenominacionID FROM Denominaciones WHERE Denominacion = '{1}'
);

-- Se muestra la nueva cantidad en la cuenta
SELECT ClientesID, D.Denominacion, Cantidad
FROM Cuentas C
LEFT JOIN Denominaciones D
ON C.DenominacionID = D.ID
WHERE ClientesID = {0}
    AND D.Denominacion = '{1}';

-- Se registra la transaccion
INSERT INTO Transacciones(ClienteID, TipoTransaccionID, CuentaFuenteID, CuentaDestinoID, DenominacionID, CantidadPrevio, CantidadPosterior, Diferencia)
VALUES(
	{0},
    (SELECT ID FROM TipoTransaccion WHERE Transaccion = 'Retiro'),
    (SELECT ID FROM Cuentas WHERE ClienteID = {0} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{1}')),
    (SELECT ID FROM Cuentas WHERE ClienteID = {0} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{1}')),
    (SELECT ID FROM Denominaciones WHERE Denominacion = '{1}'),
    (SELECT Cantidad + {2} FROM Cuentas WHERE ClienteID = {0} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{1}')),
    (SELECT Cantidad FROM Cuentas WHERE ClienteID = {0} AND DenominacionID = (SELECT ID FROM Denominaciones WHERE Denominacion = '{1}')),
    0-{2}
);