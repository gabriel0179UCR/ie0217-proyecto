CREATE TABLE Clientes (
	ID INT AUTO_INCREMENT PRIMARY KEY, 
    Nombre VARCHAR(50) NOT NULL
); 

CREATE TABLE Denominaciones (
	ID INT AUTO_INCREMENT PRIMARY KEY,
    Denominacion VARCHAR(10)
);

CREATE TABLE TipoPrestamos (
	ID INT AUTO_INCREMENT PRIMARY KEY,
    Tipo VARCHAR(50) NOT NULL,
    Interes FLOAT
);

CREATE TABLE TipoDeCambio (
	Denominacion Varchar(10) PRIMARY KEY,
    Compra FLOAT NOT NULL,
    Venta FLOAT NOT NULL
);

CREATE TABLE Cuentas (
    ID INT AUTO_INCREMENT PRIMARY KEY,
	ClientesID INT,
    DenominacionID INT NOT NULL,
    Cantidad FLOAT,
    FechaCreacion DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (ClientesID) REFERENCES Clientes(ID), 
    FOREIGN KEY (DenominacionID) REFERENCES Denominaciones(ID)
);

CREATE TABLE PrestamosClientes (
	ID INT AUTO_INCREMENT PRIMARY KEY,
    ClienteID INT NOT NULL,
	TipoPrestamoID INT NOT NULL,
    DenominacionID INT NOT NULL,
    MontoPrestamo FLOAT NOT NULL,
    Cuotas FLOAT NOT NULL,
    MontoTotal FLOAT NOT NULL,
    TotalAbonado FLOAT,
    MontoFaltante FLOAT NOT NULL,
    FechaCreacion DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FechaFinalizacion DATETIME,
    FOREIGN KEY (ClienteID) REFERENCES Clientes(ID),
    FOREIGN KEY (TipoPrestamoID) REFERENCES TipoPrestamos(ID),
    FOREIGN KEY (DenominacionID) REFERENCES Denominaciones(ID)
);

CREATE TABLE CDPs (
	ID INT AUTO_INCREMENT PRIMARY KEY,
    ClienteID INT NOT NULL,
    Monto FLOAT NOT NULL,
    DenominacionID INT NOT NULL,
    Interes FLOAT NOT NULL,
    FechaIngreso DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FechaExpiracion DATETIME NOT NULL,
    FechaCancelacion DATETIME,
    FOREIGN KEY (ClienteID) REFERENCES Clientes(ID),
    FOREIGN KEY (DenominacionID) REFERENCES Denominaciones(ID)
);

CREATE TABLE TipoTransaccion (
	ID INT AUTO_INCREMENT PRIMARY KEY,
    Transaccion VARCHAR(50) NOT NULL
);

CREATE TABLE Transacciones (
	ClienteID INT NOT NULL,
    TipoTransaccionID INT NOT NULL,
    CuentaFuenteID INT NOT NULL,
    CuentaDestinoID INT NOT NULL,
    DenominacionID INT NOT NULL,
    CantidadPrevio FLOAT NOT NULL,
    CantidadPosterior FLOAT NOT NULL,
    Diferencia FLOAT NOT NULL,
    Fecha DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (ClienteID) REFERENCES Clientes(ID),
    FOREIGN KEY (TipoTransaccionID) REFERENCES TipoTransaccion(ID),
    FOREIGN KEY (DenominacionID) REFERENCES Denominaciones(ID),
    FOREIGN KEY (CuentaFuenteID) REFERENCES Cuentas(ID),
    FOREIGN KEY (CuentaDestinoID) REFERENCES Cuentas(ID)
);