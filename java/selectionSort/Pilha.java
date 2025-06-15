import java.util.Stack;

public class Pilha {
    private Stack<Registro> elementos = new Stack<>();

    public void empilhar(Registro r) {
        elementos.push(r);
    }

    public Registro desempilhar() {
        return elementos.isEmpty() ? null : elementos.pop();
    }

    public void ordenar(Ordenador ordenador) {
        Registro[] array = elementos.toArray(new Registro[0]);
        ordenador.ordenar(array);
        elementos.clear();
        for (Registro r : array) elementos.push(r);
    }

    public void imprimir() {
        for (Registro r : elementos) System.out.println(r);
    }
}