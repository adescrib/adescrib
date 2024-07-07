import sqlite3

conn = sqlite3.connect('productos.db')
c = conn.cursor()

# Crear tabla de productos si no existe
c.execute('''CREATE TABLE IF NOT EXISTS productos
             (id INTEGER PRIMARY KEY, codigo TEXT, descripcion TEXT, cantidad INTEGER, fecha TEXT)''')

# Añadir columna productos_por_caja si no existe
def add_column_if_not_exists(cursor, table_name, column_name, column_type):
    cursor.execute(f"PRAGMA table_info({table_name})")
    columns = [info[1] for info in cursor.fetchall()]
    if column_name not in columns:
        cursor.execute(f"ALTER TABLE {table_name} ADD COLUMN {column_name} {column_type}")

add_column_if_not_exists(c, 'productos', 'productos_por_caja', 'INTEGER')

def insertar_producto(codigo, descripcion, cantidad, productos_por_caja, fecha):
    c.execute("INSERT INTO productos (codigo, descripcion, cantidad, productos_por_caja, fecha) VALUES (?, ?, ?, ?, ?)",
              (codigo, descripcion, cantidad, productos_por_caja, fecha))
    conn.commit()

def obtener_productos():
    c.execute("SELECT * FROM productos")
    return c.fetchall()

def obtener_productos_por_fecha(fecha_inicio, fecha_fin):
    query = "SELECT codigo, descripcion, cantidad, productos_por_caja, fecha FROM productos WHERE fecha BETWEEN ? AND ?"
    c.execute(query, (fecha_inicio + " 00:00:00", fecha_fin + " 23:59:59"))
    return c.fetchall()

def actualizar_productos_por_caja(codigo, productos_por_caja):
    c.execute("UPDATE productos SET productos_por_caja = ? WHERE codigo = ?", (productos_por_caja, codigo))
    conn.commit()

def cerrar_conexion():
    conn.close()

# Insertar información de productos por caja
productos_por_caja_data = [
    ('876543', 24),
    ('987654', 24)
]

for codigo, productos_por_caja in productos_por_caja_data:
    actualizar_productos_por_caja(codigo, productos_por_caja)