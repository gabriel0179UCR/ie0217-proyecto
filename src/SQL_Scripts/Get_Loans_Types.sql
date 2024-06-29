/*
Get Loans Types

Query que devuelve los tipos de prestamos y sus intereses
*/

SELECT 
    Tipo "Tipo de prestamo"
    ,CONCAT(Interes, " %") "Interes"
FROM TipoPrestamos