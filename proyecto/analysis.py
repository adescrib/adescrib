import matplotlib.pyplot as plt
from datetime import datetime
from database import obtener_productos_por_fecha
from collections import Counter
from tkinter import simpledialog

def mostrar_analisis():
    fecha_inicio = simpledialog.askstring("Fecha de inicio", "Ingrese la fecha de inicio (YYYY-MM-DD):")
    fecha_fin = simpledialog.askstring("Fecha de fin", "Ingrese la fecha de fin (YYYY-MM-DD):")
    
    productos = obtener_productos_por_fecha(fecha_inicio, fecha_fin)
    productos_por_codigo = Counter()
    ventas_por_fecha = Counter()

    for row in productos:
        productos_por_codigo[row[0]] += row[2]
        fecha = datetime.strptime(row[4], '%Y-%m-%d %H:%M:%S').date()
        ventas_por_fecha[fecha] += row[2]
    
    mostrar_productos_vendidos(productos_por_codigo)
    mostrar_ventas_por_fecha(ventas_por_fecha)

def mostrar_productos_vendidos(productos_por_codigo):
    codigos = list(productos_por_codigo.keys())
    cantidades = list(productos_por_codigo.values())

    plt.figure(figsize=(10, 5))
    plt.bar(codigos, cantidades, color='blue')
    plt.xlabel('Código de Producto')
    plt.ylabel('Cantidad Vendida')
    plt.title('Cantidad Vendida por Producto')
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()

def mostrar_ventas_por_fecha(ventas_por_fecha):
    fechas = list(ventas_por_fecha.keys())
    cantidades = list(ventas_por_fecha.values())

    plt.figure(figsize=(10, 5))
    plt.plot(fechas, cantidades, marker='o', linestyle='-', color='green')
    plt.xlabel('Fecha')
    plt.ylabel('Cantidad Vendida')
    plt.title('Ventas por Fecha')
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.show()