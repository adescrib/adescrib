from tkinter import messagebox
from datetime import datetime
from database import insertar_producto

def agregar_producto(codigo_var, descripcion_var, cantidad_var, productos_por_caja_var, actualizar_lista_productos):
    codigo = codigo_var.get()
    descripcion = descripcion_var.get()
    cantidad = cantidad_var.get()
    productos_por_caja = productos_por_caja_var.get()
    if codigo and descripcion and cantidad and productos_por_caja:
        try:
            cantidad = int(cantidad)
            productos_por_caja = int(productos_por_caja)
            fecha = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            insertar_producto(codigo, descripcion, cantidad, productos_por_caja, fecha)
            actualizar_lista_productos()
            codigo_var.set("")
            descripcion_var.set("")
            cantidad_var.set("")
            productos_por_caja_var.set("")
        except ValueError:
            messagebox.showerror("Error", "Por favor, ingrese valores válidos.")
    else:
        messagebox.showerror("Error", "Por favor, complete todos los campos.")