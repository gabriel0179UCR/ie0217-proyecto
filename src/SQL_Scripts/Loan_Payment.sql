/*
Loan Payment

Query que actualiza la cantidad de dinero abonada y faltante

Parametros:
- {0}: ID del prestamo
- {1}: Cantidad a abonar
*/

UPDATE PrestamosClientes
SET TotalAbonado = TotalAbonado + {1}, MontoFaltante = MontoFaltante - {1}
WHERE ID = {0};

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
WHERE PC.ID = {0};