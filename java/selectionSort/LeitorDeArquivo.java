import java.io.*;
import java.util.ArrayList;

public class LeitorDeArquivo {
    public static Registro[] lerRegistros(String caminho) throws IOException {
        ArrayList<Registro> lista = new ArrayList<>();
        BufferedReader leitor = new BufferedReader(new FileReader(caminho));
        String linha;
        while ((linha = leitor.readLine()) != null) {
            String[] partes = linha.split(",");
            if (partes.length >= 3) { // Pega o terceiro valor (nota)
                try {
                    double nota = Double.parseDouble(partes[2].trim());
                    // Converte nota para inteiro (ex: 5.0 -> 50)
                    int chave = (int) (nota * 10); 
                    lista.add(new Registro(chave));
                } catch (NumberFormatException ignored) {}
            }
        }
        leitor.close();
        return lista.toArray(new Registro[0]);
    }
}