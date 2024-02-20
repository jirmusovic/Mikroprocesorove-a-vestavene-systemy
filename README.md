# IMP
14/14

Cílem je vytvořit terminál s klávesnicí a dvěma ledkami (otevřeno / zavřeno).
Desku ESP32 s periferiemi si vyzvednete u vedoucího (před tím vám pošle e-mail)
Požadavky na výslednou aplikaci
K programování můžete využít prostředí Arduino nebo IDF. Na hodnocení se bude promítat i komplexnost řešení - pokud použijete Arduino, očekává se, že pro získání plného počtu bodů se budete snažit aplikaci co nejvíce "dotáhnout". Maticovou klávesnici však musíte vyčítat manuálně, bez využití knihovny!
K desce bude připojená maticová klávesnice a dvě LED diody - zelená a červená. Po zadání správného přístupového kódu se na chvíli otevře (rozsvítí zelená), pak se zase přejde do zamklého (červeného) stavu.
Není povoleno použít knihovnu pro práci s klávesnicí! Pracujte s ní přes GPIO vstupy / výstupy.
Přístupový kód bude nastavitelný - po zadání speciálního kódu (např. #1234*5678) se změní kód z 1234 na 5678. Měl by být uložený i po odpojení napájení.
Zamyslete se nad ovládáním a nad rozumnou signalizací i za použití dvou LED
Vycházejte z dokumentace IDF, popisu v e-learningu a ukázek.
Vytvořte přehlednou dokumentaci k přípravě, způsobu realizace, k funkčnosti a vlastnostem řešení projektu.
Řešení (projekt, bez binárních souborů sestavitelných na základě zdrojových souborů v projektu, a dokumentaci ve zdrojové i binární, tj. PDF, podobě) odevzdávejte prostřednictvím IS v jediném ZIP archívu.
Předvedení řešení se předpokládá buď v osobní podobě, s následným vrácením zapůjčeného vybavení, nebo s odevzdáním videa (např. na youtube, google drive a podobně). V případě nejasností však můžete být vyzváni k osobní prezentaci řešení. Zařízení potom navrátíte vedoucímu
Hodnocení projektu bude provedeno na základě: dokumentace (4 body), funkčnosti (5), prezentace (1) a kvality řešení (4). Samozřejmě u nefunkčního řešení nemůže být plné hodnocení dokumentace, protože zjevně nepopisuje pravý stav věci. Podobně v kvalitě hodnocení bude zahrnuto i to, jestli vaše řešení splňuje minimální požadavky. Také se bude hodnotit, zda je to pouhé volání malého množství funkcí z knihovny s vaším nulovým přínosem, či naopak je dodělané z pohledu řešení různých chyb, domyšlení ovládání či případného rozšíření.
