import tkinter as tk
from tkinter import ttk, messagebox
from database import obtener_productos
from excel_import import importar_excel
from user_input import agregar_producto
from analysis import mostrar_analisis
from pedido import generar_pedido

def actualizar_lista_productos(lista_productos, total_ventas_var):
    lista_productos.delete(*lista_productos.get_children())
    productos = obtener_productos()
    productos_por_codigo = {}
    total_ventas = 0
    for row in productos:
        if row[1] not in productos_por_codigo:
            productos_por_codigo[row[1]] = {'descripcion': row[2], 'cantidad': 0, 'productos_por_caja': row[4], 'fecha': row[5]}
        productos_por_codigo[row[1]]['cantidad'] += row[3]
        total_ventas += row[3]

    for codigo, datos in productos_por_codigo.items():
        lista_productos.insert("", "end", values=(codigo, datos['descripcion'], datos['cantidad'], datos['productos_por_caja'], datos['fecha']))
    
    total_ventas_var.set(f"Total de Productos: {total_ventas} unidades")

def crear_interfaz(root):
    root.geometry("1000x700")
    
    # Crear un estilo
    style = ttk.Style()
    style.theme_use("clam")
    
    # Configurar el estilo
    style.configure("TLabel", font=("Arial", 14), padding=5)
    style.configure("TButton", font=("Arial", 14), padding=5, background="#4CAF50", foreground="white")
    style.configure("TEntry", font=("Arial", 14))
    style.configure("Treeview.Heading", font=("Arial", 14), background="#4CAF50", foreground="white")
    style.configure("Treeview", font=("Arial", 12))

    # Configurar los estilos de los botones para que cambien de color al pasar el cursor sobre ellos
    style.map("TButton", 
              background=[("active", "#45a049"), ("disabled", "#d3d3d3")], 
              foreground=[("active", "white"), ("disabled", "#a9a9a9")])
    
    # Variables
    codigo_var = tk.StringVar()
    descripcion_var = tk.StringVar()
    cantidad_var = tk.StringVar()
    productos_por_caja_var = tk.StringVar()
    total_ventas_var = tk.StringVar()

    # Frame para entrada de datos
    frame_entrada = ttk.Frame(root, padding="10", style="TFrame")
    frame_entrada.grid(row=0, column=0, padx=10, pady=10, sticky="ew")

    ttk.Label(frame_entrada, text="Código del Producto:", style="TLabel").grid(row=0, column=0, sticky="w")
    ttk.Entry(frame_entrada, textvariable=codigo_var, width=30, style="TEntry").grid(row=0, column=1, sticky="ew")

    ttk.Label(frame_entrada, text="Descripción:", style="TLabel").grid(row=1, column=0, sticky="w")
    ttk.Entry(frame_entrada, textvariable=descripcion_var, width=30, style="TEntry").grid(row=1, column=1, sticky="ew")

    ttk.Label(frame_entrada, text="Cantidad:", style="TLabel").grid(row=2, column=0, sticky="w")
    ttk.Entry(frame_entrada, textvariable=cantidad_var, width=30, style="TEntry").grid(row=2, column=1, sticky="ew")

    ttk.Label(frame_entrada, text="Productos por Caja:", style="TLabel").grid(row=3, column=0, sticky="w")
    ttk.Entry(frame_entrada, textvariable=productos_por_caja_var, width=30, style="TEntry").grid(row=3, column=1, sticky="ew")

    ttk.Button(frame_entrada, text="Agregar Producto", command=lambda: agregar_producto(codigo_var, descripcion_var, cantidad_var, productos_por_caja_var, lambda: actualizar_lista_productos(lista_productos, total_ventas_var)), style="TButton").grid(row=4, column=0, columnspan=2, pady=5)

    ttk.Button(frame_entrada, text="Importar desde Excel", command=importar_excel, style="TButton").grid(row=5, column=0, columnspan=2, pady=5)

    # Frame para lista de productos
    frame_lista = ttk.Frame(root, padding="10", style="TFrame")
    frame_lista.grid(row=1, column=0, padx=10, pady=10, sticky="nsew")

    columnas = ("codigo", "descripcion", "cantidad", "productos_por_caja", "fecha")
    lista_productos = ttk.Treeview(frame_lista, columns=columnas, show="headings", style="Treeview")
    for col in columnas:
        lista_productos.heading(col, text=col.capitalize())
        lista_productos.column(col, anchor="center")
    lista_productos.pack(expand=True, fill="both")

    # Frame para análisis y total de ventas
    frame_total = ttk.Frame(root, padding="10", style="TFrame")
    frame_total.grid(row=2, column=0, padx=10, pady=10, sticky="ew")

    ttk.Label(frame_total, textvariable=total_ventas_var, style="TLabel").pack(side="left")
    ttk.Button(frame_total, text="Ver Análisis de Productos", command=mostrar_analisis, style="TButton").pack(side="right")
    
    ttk.Button(frame_total, text="Generar Pedido Sugerido", command=generar_pedido, style="TButton").pack(side="right")

    actualizar_lista_productos(lista_productos, total_ventas_var)

    # Configurar expansión
    root.grid_rowconfigure(1, weight=1)
    root.grid_columnconfigure(0, weight=1)

# Ejemplo de cómo iniciar la aplicación
if __name__ == "__main__":
    root = tk.Tk()
    root.title("Sistema de Gestión de Productos de Tienda")
    crear_interfaz(root)
    root.mainloop()