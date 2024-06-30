/*
Get Interest Loan

Query que optiene el interes de un prestamo

Parametros:
- {0}: Tipo de prestamo (Personal, Prendario, Hipotecario)
*/
SELECT 
   Interes 
FROM TipoPrestamos 
WHERE Tipo = '{0}';