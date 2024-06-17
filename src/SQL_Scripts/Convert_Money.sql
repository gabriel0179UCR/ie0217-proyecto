/*
Convert_Money

Query que realiza la conversion del dinero segun el tipo de cambio

Parametros
- {0}: Denominacion del dinero (ej. 'Colones')
- {1}: Denominacion a convertir (ej. 'Dolares')
- {2}: Cantidad
*/

-- Se devuelve la cantidad convertida
SELECT CASE WHEN '{0}' != 'Colones' THEN {2}*Compra ELSE {2}/Venta END AS Monto
FROM TipoDeCambio
WHERE Denominacion = CASE WHEN '{0}' = 'Colones' THEN '{1}' ELSE '{0}' END;
