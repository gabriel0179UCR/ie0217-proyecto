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

INSERT INTO PrestamosClientes (
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