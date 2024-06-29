/*
Loan

Query que genera un prestamo asociado a un cliente

Parametros:
- {0}: ID del cliente
- {1}: Tipo de prestamo (Personal, Prendario, Hipotecario)
- {2}: Denominacion (Colones, Dolares)
- {3}: Monto del prestamo
- {4}: Cuotas en anios
*/

-- Se guarda en LastID el ultimo ID de la tabla Clientes
WITH LastID AS (
  SELECT COALESCE(MAX(ID), 0) AS LastID
  FROM PrestamosClientes
)

INSERT INTO PrestamosClientes (
    ID,
    ClienteID, 
    TipoPrestamoID, 
    DenominacionID, 
    MontoPrestamo, 
    Cuotas, 
    MontoTotal, 
    TotalAbonado, 
    MontoFaltante, 
    FechaFinalizacion
)
VALUES (
    (SELECT LastID + 1 FROM LastID),
	{0}, 
    (SELECT ID FROM TipoPrestamos WHERE Tipo = '{1}'), 
    (SELECT ID FROM Denominaciones WHERE Denominacion = '{2}'),
    {3}, 
    12*{4},
    (SELECT {3}*(1 + Interes/100) FROM TipoPrestamos WHERE Tipo = '{1}'),
    0,
    (SELECT {3}*(1 + Interes/100) FROM TipoPrestamos WHERE Tipo = '{1}'),
    NULL
);


SELECT 
    PC.ID "ID del prestamo"
    ,PC.ClienteID "ID del cliente"
    ,TP.Tipo "Tipo de prestamo"
    ,D.Denominacion "Denominacion"
    ,PC.MontoPrestamo "Monto del prestamo"
    ,PC.Cuotas "Cuotas (meses)"
    ,PC.MontoTotal "Monto total"
    ,PC.TotalAbonado "Total abonado"
    ,PC.MontoFaltante "Monto faltante"
    ,PC.FechaCreacion "Fecha de creacion"
    ,PC.FechaFinalizacion "Fecha de cancelacion"
FROM PrestamosClientes PC 
LEFT JOIN TipoPrestamos TP ON TP.ID = PC.TipoPrestamoID
LEFT JOIN Denominaciones D ON D.ID = PC.DenominacionID
ORDER BY PC.ID DESC LIMIT 1;