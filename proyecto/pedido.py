from fpdf import FPDF
from datetime import datetime, timedelta
from database import obtener_productos_por_fecha

class PDF(FPDF):
    def header(self):
        self.set_font('Arial', 'B', 12)
        self.cell(0, 10, 'Pedido Sugerido', 0, 1, 'C')

    def footer(self):
        self.set_y(-15)
        self.set_font('Arial', 'I', 8)
        self.cell(0, 10, f'Page {self.page_no()}', 0, 0, 'C')

    def chapter_title(self, title):
        self.set_font('Arial', 'B', 12)
        self.cell(0, 10, title, 0, 1, 'L')
        self.ln(5)

    def chapter_body(self, body):
        self.set_font('Arial', '', 12)
        self.multi_cell(0, 10, body)
        self.ln()

def generar_pedido():
    fecha_fin = datetime.now()
    fecha_inicio = fecha_fin - timedelta(days=7)
    productos = obtener_productos_por_fecha(fecha_inicio.strftime('%Y-%m-%d'), fecha_fin.strftime('%Y-%m-%d'))

    productos_por_codigo = {}
    for row in productos:
        codigo = row[0]
        descripcion = row[1]
        cantidad = row[2]
        productos_por_caja = row[3]
        if codigo not in productos_por_codigo:
            productos_por_codigo[codigo] = {'descripcion': descripcion, 'cantidad': 0, 'productos_por_caja': productos_por_caja}
        productos_por_codigo[codigo]['cantidad'] += cantidad

    pedido = []
    for codigo, datos in productos_por_codigo.items():
        if datos['productos_por_caja'] and datos['productos_por_caja'] > 0:
            cantidad_cajas = (datos['cantidad'] + 1) // datos['productos_por_caja']
            if (datos['cantidad'] + 1) % datos['productos_por_caja'] > 0:
                cantidad_cajas += 1
            pedido.append((codigo, datos['descripcion'], cantidad_cajas, datos['productos_por_caja']))
        else:
            pedido.append((codigo, datos['descripcion'], datos['cantidad'] + 1, 'N/A'))

    pdf = PDF()
    pdf.add_page()
    pdf.chapter_title('Lista de Pedido Sugerido')

    for item in pedido:
        pdf.chapter_body(f'Código del Producto: {item[0]}\nDescripción: {item[1]}\nCantidad Sugerida (Cajas): {item[2]}\nProductos por Caja: {item[3]}')

    pdf.output('pedido_sugerido.pdf')
    print('Pedido sugerido generado con éxito: pedido_sugerido.pdf')
