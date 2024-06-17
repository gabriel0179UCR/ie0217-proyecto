/*
Verify_ClientID_Exist

Query que verifica si el ID del cliente existe

Parametros
- {0}: ID del cliente
*/

-- Se devuelve 1 si el ID existe y 0 si el ID no existe
SELECT EXISTS (
SELECT 1 FROM Clientes WHERE ID = {0}
);