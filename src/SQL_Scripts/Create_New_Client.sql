/*
Create_New_Client

Query que permite crear un nuevo cliente en la base de datos

Parametros
- {0}: Nombre del cliente
*/

-- Se guarda en LastID el ultimo ID de la tabla Clientes
WITH LastID AS (
  SELECT COALESCE(MAX(ID), 0) AS LastID
  FROM Clientes
)

-- Se crea la fila en la tabla Clientes con el nuevo nombre
INSERT INTO Clientes (ID, Nombre)
VALUES (
    (SELECT LastID + 1 FROM LastID),
    '{0}'
);

-- Se crea la cuenta: Colones
INSERT INTO Cuentas (ID, ClientesID, DenominacionID, Cantidad)
VALUES (
    (SELECT COALESCE(MAX(ID), 0) + 1 FROM Cuentas),
    (SELECT MAX(ID) FROM Clientes WHERE Nombre = '{0}'),
    1,
    0
);

-- Se crea la cuenta: Dolares
INSERT INTO Cuentas (ID, ClientesID, DenominacionID, Cantidad)
VALUES (
    (SELECT COALESCE(MAX(ID), 0) + 1 FROM Cuentas),
    (SELECT MAX(ID) FROM Clientes WHERE Nombre = '{0}'),
    2,
    0
);

-- Se muestra el ID del nuevo cliente
SELECT ID 
FROM Clientes 
WHERE Nombre = '{0}'
ORDER BY ID DESC
LIMIT 1;
