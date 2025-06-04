import java.util.LinkedList;

public class Lista {
    private LinkedList<Registro> elementos = new LinkedList<>();

    public void adicionar(Registro r) {
        elementos.add(r);
    }

    public void remover(Registro r) {
        elementos.remove(r);
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