-- Last ID with handle for empty table (First value null)
WITH LastID AS (
  SELECT COALESCE(MAX(ID), 0) AS LastID
  FROM Clientes
)

-- Create New Cliente row: Insert ID and Nombre to Clientes table
INSERT INTO Clientes (ID, Nombre)
VALUES (
    (SELECT LastID + 1 FROM LastID),
    '{0}'
);

-- Create Accounts: Colons
INSERT INTO Cuentas (ClientesID, DenominacionID, Cantidad)
VALUES (
    (SELECT MAX(ID) FROM Clientes WHERE Nombre = '{0}'),
    1,
    0
);

-- Create Accounts: Dolares
INSERT INTO Cuentas (ClientesID, DenominacionID, Cantidad)
VALUES (
    (SELECT MAX(ID) FROM Clientes WHERE Nombre = '{0}'),
    2,
    0
);

-- Return ID of the inserted client
SELECT ID 
FROM Clientes 
WHERE Nombre = '{0}'
ORDER BY ID DESC
LIMIT 1;
