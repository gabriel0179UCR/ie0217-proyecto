/*
Verify_Money_Available

Query que devuelve la cantidad de dinero en una cuenta

Parametros
- {0}: ID del cliente
- {1}: Denominacion (ej: Colones)
*/

-- Se muestra la cantidad de dinero en la cuenta
SELECT C.Cantidad
FROM Cuentas C
LEFT JOIN Denominaciones D
ON C.DenominacionID = D.ID
WHERE ClientesID = {0}
    AND D.Denominacion = '{1}'
LIMIT 1;