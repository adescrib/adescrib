import pandas as pd
from tkinter import filedialog, messagebox
from datetime import datetime
from database import insertar_producto

def importar_excel():
    file_path = filedialog.askopenfilename(filetypes=[("Excel files", "*.xlsx *.xls")])
    if file_path:
        df = pd.read_excel(file_path)
        for index, row in df.iterrows():
            codigo = row['Codigo']
            descripcion = row['Descripcion']
            cantidad = row['Cantidad']
            productos_por_caja = row['ProductosPorCaja'] if 'ProductosPorCaja' in row else None
            fecha = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            insertar_producto(codigo, descripcion, cantidad, productos_por_caja, fecha)
        messagebox.showinfo("Importación Exitosa", "Los datos se han importado correctamente.")