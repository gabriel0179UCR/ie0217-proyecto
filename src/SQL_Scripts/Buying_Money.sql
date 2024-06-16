SELECT CASE WHEN '{0}' != 'Colones' THEN {2}*Compra ELSE {2}/Venta END AS Monto
FROM TipoDeCambio
WHERE Denominacion = CASE WHEN '{0}' = 'Colones' THEN '{1}' ELSE '{0}' END;
