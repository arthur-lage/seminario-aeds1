import java.util.LinkedList;

public class Fila {
    private LinkedList<Registro> elementos = new LinkedList<>();

    public void enfileirar(Registro r) {
        elementos.addLast(r);
    }

    public Registro desenfileirar() {
        return elementos.isEmpty() ? null : elementos.removeFirst();
    }

    public void ordenar(Ordenador ordenador) {
        Registro[] array = elementos.toArray(new Registro[0]);
        ordenador.ordenar(array);
        elementos.clear();
        for (Registro r : array) elementos.add(r);
    }

    public void imprimir() {
        for (Registro r : elementos) System.out.println(r);
    }
}