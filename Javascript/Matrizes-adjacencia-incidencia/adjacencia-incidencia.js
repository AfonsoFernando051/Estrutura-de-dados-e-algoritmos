const readlineSync = require('readline-sync');

function matrizIncidencia(array) {
    const col = array.length + 3;
    const linhas = array.length;

    const matrizIncidencia = [];

    for (let i = 0; i < linhas; i++) {
        matrizIncidencia[i] = [];
        for (let j = 0; j < col; j++) {
            if (j === 0) {
                matrizIncidencia[i][j] = array[i];
            } else {
                matrizIncidencia[i][j] = Math.floor(Math.random() * 2);
            }
        }
    }
    return matrizIncidencia;
}

function matrizAdjacente(array) {
    const colunas = array.length + 1;
    const linhas = array.length;

    const matrizAdjacente = [];

    for (let i = 0; i < linhas; i++) {
        matrizAdjacente[i] = [];
        for (let j = 0; j < colunas; j++) {
            if (j === 0) {
                matrizAdjacente[i][j] = array[i];
            } else {
                matrizAdjacente[i][j] = Math.floor(Math.random() * 2);
            }
        }
    }
    return matrizAdjacente;
}

function grauVertice(matriz, vert) {
    let grau = 0;

    for (let i = 0; i < matriz.length; i++) {
        let acheiVertice = false;
        for (let j = 0; j < matriz[i].length; j++) {
            if (matriz[i][j] === vert) {
                acheiVertice = true;
            }
            if (j !== 0 && acheiVertice) {
                if (matriz[i][j] !== 0) {
                    grau++;
                }
            }
        }
    }
    return grau;
}

function conjuntoGrafo(matriz, array) {
    const vert = [];
    const arestas = [];

    const matrizIndex = matrizIndexada(matriz, array);

    vert.push("V={");
    arestas.push("A={ ");

    for (let i = 0; i < matrizIndex.length; i++) {
        for (let j = 0; j < matrizIndex[i].length; j++) {
            if (i === 0 && j + 1 === matrizIndex[i].length) {
                vert.push(`${matrizIndex[i][j]}}`);
            } else if (i === 0 && j !== 0) {
                vert.push(`${matrizIndex[i][j]},`);
            }

            if (i !== 0 && j !== 0) {
                if (matrizIndex[i][j] !== 0) {
                    arestas.push(`{${matrizIndex[i][0]},${matrizIndex[0][j]}}`);
                }
            }
        }
    }
    arestas.push("}");

    return `${vert.join(' ')} - ${arestas.join(' ')}`;
}

function matrizIndexada(matrz, array) {
    const linhas = matrz.length + 1;
    const colunas = matrz[0].length;
    const matrizIndex = [];

    for (let i = 0; i < linhas; i++) {
        matrizIndex[i] = [];
        for (let j = 0; j < colunas; j++) {
            if (i === 0 && j === 0) {
                matrizIndex[i][j] = -1;
            } else if (i === 0) {
                matrizIndex[i][j] = array[j - 1];
            } else {
                matrizIndex[i][j] = matrz[i - 1][j];
            }
        }
    }

    return matrizIndex;
}

function printMatrix(matrix) {
    console.log("_____________________________");
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            if (j === 0) {
                process.stdout.write(matrix[i][j] + "-> ");
            } else {
                process.stdout.write(matrix[i][j] + "  ");
            }
        }
        console.log();
    }
    console.log("_____________________________");
}

function main() {
    // A
    console.log("Digite a quantidade de valores a inserir: ");
    const qtdValores = parseInt(readlineSync.prompt());

    const array = [];

    for (let i = 0; i < qtdValores; i++) {
        console.log(`Digite o ${i + 1}º número: `);
        const valor = parseInt(readlineSync.prompt());
        array.push(valor);
    }

    // B
    const matrizIncid = matrizIncidencia(array);

    console.log("Matriz De Incidencia: ");
    printMatrix(matrizIncid);

    // C
    const matrizAdjacent = matrizAdjacente(array);

    console.log("Matriz De Adjacencia: ");
    printMatrix(matrizAdjacent);

    // E
    let vertice;

    do {
        console.log("_______________");
        console.log(array.join(" "));
        console.log("_______________");

        console.log("Escolha qual dos vertices acima deseja calcular o grau d(V): ");
        vertice = parseInt(readlineSync.prompt());

        if (array.includes(vertice)) {
            break;
        } else {
            console.log("Informe um vertice valido!!!");
        }

    } while (true);

    console.log("_____________________________");
    console.log(`Grau do vertice ${vertice}: ${grauVertice(matrizIncid, vertice)}`);
    console.log("_____________________________");

    // F
    console.log(conjuntoGrafo(matrizAdjacent, array));
}

main();
