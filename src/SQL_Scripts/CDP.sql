/*
CDP

Query que crea CDPs

Parametros:
- {0}: ID del cliente
- {1}: Cantidad ingresada al CDP
- {2}: Denominacion
- {3}: Fecha de expiracion

*/

-- Se guarda en LastID el ultimo ID de la tabla Clientes
WITH LastID AS (
  SELECT COALESCE(MAX(ID), 0) AS LastID
  FROM CDPs
)

INSERT INTO CDPs(
    ID
    ,ClienteID
    ,Monto
    ,DenominacionID
    ,Interes
    ,FechaExpiracion
    ,FechaCancelacion
    )
VALUES (
    (SELECT LastID + 1 FROM LastID),
    {0}, 
    {1}, 
    (SELECT ID FROM Denominaciones WHERE Denominacion = '{2}'), 
    7, 
    '{3}',
    NULL
);


SELECT 
    CDP.ID "ID del CDP"
    ,CDP.Monto "Monto"
    ,D.Denominacion "Denominacion"
    ,CDP.Interes "Interes"
    ,CDP.FechaExpiracion "Fecha de expiracion"
FROM CDPs CDP
LEFT JOIN Denominaciones D ON D.ID = CDP.DenominacionID
ORDER BY CDP.ID DESC LIMIT 1;