# Harry Potter Theme

<img style = "width: 200px" src = "https://static-00.iconduck.com/assets.00/file-type-arduino-icon-512x512-lyuj2qji.png" alt = "Arduino"> <img style = "width: 200px" src = "https://aux.iconspalace.com/uploads/2142641057408204296.png" alt = "Harry Potter">

Projeto Arduino da música tema de **Harry Potter**.

## Sobre o Projeto

Buscando transcrever a melodia do clássico filme de **Harry Potter**, esse projeto utiliza componentes eletrônicos de fácil acesso e propõe um estudo interessante sobre música. 

## Tecnologias Utilizadas
- Arduino
- Componentes Eletrônicos
- Línguagem C++

## Como executar o projeto
```bash
# clonar repositório
git clone https://github.com/PhilTisoni/Arduino-Harry_Potter_Theme.git

# executar o projeto
./Arduino-Harry_Potter_Theme spring-boot:run
```
Após clonar o projeto, adicione o código em seu Arduino conectado aos componentes eletrônicos.

# Índice

- <a href = "#Eletrônica">Eletrônica</a>
- <a href = "#Teoria-Musical">Teoria Musical</a>
- <a href = "#Física">Física</a>
- <a href = "#Teoria-e-Prática">Teoria e Prática</a>
- <a href = "#Materiais-Complementares">Materiais Complementares</a>
- <a href = "#Autor">Autor</a>

# Eletrônica

## Lista de Componentes

Para entender o funcionamento do projeto, precisamos explanar alguns conceitos sobre Eletrônica, Música e Física, mas não se assuste, tentarei utilizar uma linguagem simples e detalhada sobre o tema. Desse modo, vamos começar com a lista de componentes necessários para o projeto:

- Placa Arduino (Uno, Leonardo, Mega ou outro modelo compatível)
- Protoboard
- LED
- Buzzer 
- Resistor 220Ω (ou outro valor de sua preferência)
- Fios

Esses componentes podem ser encontrados facilmente em uma loja de eletrônica da sua cidade ou adquiridos na internet.

## Circuito

<img style = "width: 700px" src = "http://arduinoandme.weebly.com/uploads/4/3/1/8/43188849/2453055.jpg" alt = "Circuito Eletrônico"> 

                           Esquema da Montagem do Circuito Eletrônico
 
Conecte os componentes como a imagem acima, tenha **cuidado** para não confundir os terminais positivos e negativos, então, tente conectar **exatamente** como a figura. Caso você **não tenha experiência**, estou deixando alguns <a href = "#Materiais-Complementares">materiais complementares</a> no final desse documento.

**Dica:** A intensidade e o timbre da música são modificados ao alterar o valor do resistor, você pode experimentar valores diferentes ou utilizar um potenciômetro para obter maior controle.

Para marcar o tempo da música e criar um efeito visual interessante, foi adicionado um método para acender e apagar o LED:

```.ino
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{ 
    digitalWrite(ledPin, HIGH);	   
    
    int x; 	 
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++) 	 
    { 	 
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW);
        delayMicroseconds(delayAmount);
    } 	 
    
    digitalWrite(ledPin, LOW);    
    delay(20);  // Pequeno delay para marcar e separar as notas   
} 	 
```

Esse método cria um pequeno atraso e faz com que o LED pisque com uma marcação conforme as notas são tocadas, sincronizando com o som emitido pelo buzzer. 

# Teoria Musical

## Notas Musicais

O sistema ocidental inclui 7 notas musicais (Dó, Ré, Mi, Fá, Sol, Lá e Si) e seus acidentes, chamados **sustenido** (aumenta um semitom) e **bemol** (diminui um semitom). Não se preocupe com os nomes, para o nosso código, é necessário entender que essas notas e acidentes são representadas através de letras e símbolos, como a figura abaixo:

<img style = "width: 400px" src = "https://miro.medium.com/v2/resize:fit:707/0*qTiVNXkX-vVL72Fo.jpg" alt = "Notas Musicais"> 

                         Notas Musicais

Nosso circuito será capaz de executar uma **melodia**, ou seja, uma sequência de notas tocadas uma a uma com um determinado rítmo. 

## Melodia

Para configurar o Arduino, usaremos os conceitos de **Altura** e **Duração**:

- **Altura:** Sons graves e agudos
- **Duração:** Sons Longos e curtos

Essas propriedades (e algumas outras) compõe o som e consequêntemente, são fundamentais para a criação de uma **melodia**.

# Física

As alturas são determinadas através da frequência do som, ou seja, pela quantidade de ciclos de uma onda, sendo medidos por segundo (Hz). Para facilitar o entendimento, observe essa tabela:

<img style = "width: 700px" src = "https://2.bp.blogspot.com/-mhsT0jYklf0/V2yZ-DPafMI/AAAAAAAAA7M/78_dxDNPgyAwYwQzhyYBL_H07z6MVnusQCLcB/s1600/frequencias.jpg" alt = "Tabela de Frequências"> 

                                   Tabela de Frequênicas

Ao final de cada oitava, a nota se repete com uma altura mais aguda, assim, o **Dó na terceira oitava** é mais grave que o **Dó na quinta oitava**. Repare também que quanto **mais agudo** o som, **maior** será a sua **frequência**.

# Teoria e Prática

O código do Arduino foi elaborado a partir desses conceitos, as notas foram definidas utilizando as cifras e suas respectivas frequências:
```.ino
#define as4 466 // Lá Sustenido (A#) na quarta oitava, possuindo 466 Hz de frequência
#define b4 494  // Si (B) na quarta oitava, possuindo 494 Hz de frequência
#define ds5 622 // Rè Sustenido (D#) na quinta oitava, possuindo 622 Hz de frquência
```

A duração das notas foi escrito a parir do andamento (velocidade) de 80 bpm (batidas por minuto), assim, podemos entender que a unidade de tempo corresponde a 750ms.
Para modificar a velocidade, basta alterar os valores seguindo a mesma proporção, por exemplo, para fazer uma nota mais rápida, como uma **colcheia**, basta dividir o valor pela metade (750 / 2 = 375ms).

```.ino  	 
void hp()
{       
    beep(speakerPin, b4, 375); 
    beep(speakerPin, e5, 563);     
    beep(speakerPin, g5, 188); 
    beep(speakerPin, fs5, 375); // valor de colcheia (nota mais rápida) - 750 / 2 = 375ms para a nota F# (Fá Sustenido na quinta oitava) 
    beep(speakerPin, e5, 750);  // Valor de semínima (unidade de tempo) = 750ms para a nota E (Mí - na quinta oitava)  
}
```

Agora que você entendeu a aplicação da teoria na prática, vamos aos resultados!

# Materiais Complementares

- [Buzzer](https://mundoprojetado.com.br/buzzer-como-usar-com-o-arduino/)
- [Resistores](https://www.mundodaeletrica.com.br/aprenda-como-calcular-resistor-para-led/#:~:text=Para%20o%20led%20vermelho%3A&text=Como%20vai%20ser%20muito%20dif%C3%ADcil,valor%20mais%20pr%C3%B3ximo%20do%20calculado.)
- [Partitura](https://www.youtube.com/watch?v=GQW8IyultNk)
- [Conversor de BPM para Milisegundos](https://tuneform.com/tools/time-tempo-bpm-to-milliseconds-ms)

# Autor

Phelipe Augusto Tisoni

https://www.linkedin.com/in/phelipetisoni
