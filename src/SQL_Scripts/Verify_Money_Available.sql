-- Show Client Quantity
SELECT C.Cantidad
FROM Cuentas C
LEFT JOIN Denominaciones D
ON C.DenominacionID = D.ID
WHERE ClientesID = {0}
    AND D.Denominacion = '{1}'
LIMIT 1;