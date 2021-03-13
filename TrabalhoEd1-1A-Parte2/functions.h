#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define TOTALLOTES 20
#define TOTALTONEIS 20
#define TOTALTUBOS 100
typedef struct {
        int cimento;
        int areia;
        int cal;
        int tubos;
        int saibro;
    } Lote;
Lote lote[TOTALLOTES];

int   mostrandoValorPorLote(char strProduto[10]);
void  listarQuantidadeTotalMaterialLote(void);
void  inicializandoVetorLotes(void);
int   ComparaStrings(char strCalculo[10]);
void  menuPrograma(void);
void  listarMaterialPorLote(void);
int   RetiraMaterialLote(char tipoMaterial[10]);
int   verificaLoteAddLote(int qtd, int loteEsc,char tipoProd[10]);

#endif // FUNCTIONS_H_INCLUDED
