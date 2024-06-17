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