import tkinter as tk
from gui import crear_interfaz

if __name__ == "__main__":
    root = tk.Tk()
    root.title("Sistema de Gestión de Productos de Tienda")
    crear_interfaz(root)
    root.mainloop()
    