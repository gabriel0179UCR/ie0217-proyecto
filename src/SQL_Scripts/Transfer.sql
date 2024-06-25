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