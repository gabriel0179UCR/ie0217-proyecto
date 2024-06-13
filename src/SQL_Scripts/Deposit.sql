/*
Deposit

Query to update the quantity in the account

Parameters
- {0}: Client ID
- {1}: Denomination (ex. 'Colones')
- {2}: Quantity
*/

-- Update row in Cuentas
UPDATE Cuentas SET Cantidad = Cantidad + {2} WHERE ClientesID = {0} AND DenominacionID = (
    SELECT ID AS DenominacionID FROM Denominaciones WHERE Denominacion = '{1}'
);

-- Show the new quantity in the count
SELECT ClientesID, D.Denominacion, Cantidad
FROM Cuentas C
LEFT JOIN Denominaciones D
ON C.DenominacionID = D.ID
WHERE ClientesID = {0}
    AND D.Denominacion = '{1}';