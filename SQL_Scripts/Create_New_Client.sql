-- Insert ID and Nombre to Clientes table
--INSERT INTO Clientes (ID, Nombre)
--VALUES ((SELECT ID FROM Clientes ORDER BY ID DESC LIMIT 1) + 1, '{0}');

-- Return ID of the inserted client
SELECT ID 
FROM Clientes 
WHERE Nombre = '{0}'
ORDER BY ID DESC
LIMIT 1 