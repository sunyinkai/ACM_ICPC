#include<cstdio>
#include<unordered_map>
using namespace std;
long long a[3000]=
{
0 ,43051 ,91191 ,141273 ,192584 ,244959 ,297950 ,351568 ,405683 ,460399 ,515459 ,570900 ,626633 ,682779 ,739045 ,795692 ,852483 ,909587 ,966912 ,1024390 ,1082052 ,1140025 ,1198114 ,1256322 ,1314718 ,1373276 ,1432028 ,1490835 ,1549817 ,1608989 ,1668193 ,1727545 ,1787135 ,1846643 ,1906390 ,1966195 ,2026146 ,2086096 ,2146136 ,2206431 ,2266667 ,2327135 ,2387549 ,2448152 ,2508871 ,2569601 ,2630462 ,2691445 ,2752371 ,2813462 ,2874639 ,2935915 ,2997158 ,3058528 ,3120032 ,3181515 ,3243119 ,3304757 ,3366520 ,3428094 ,3489932 ,3552044 ,3613936 ,3675992 ,3738181 ,3800237 ,3862490 ,3924649 ,3986994 ,4049282 ,4111735 ,4174216 ,4236737 ,4299181 ,4361698 ,4424465 ,4487066 ,4549842 ,4612686 ,4675533 ,4738511 ,4801405 ,4864289 ,4927289 ,4990388 ,5053627 ,5116664 ,5179914 ,5243229 ,5306643 ,5369867 ,5433318 ,5496754 ,5560189 ,5623791 ,5687265 ,5750870 ,5814434 ,5878078 ,5941713 ,6005474 ,6069335 ,6133203 ,6196958 ,6260885 ,6324796 ,6388725 ,6452693 ,6516762 ,6580831 ,6644824 ,6708952 ,6773127 ,6837116 ,6901373 ,6965625 ,7029992 ,7094214 ,7158539 ,7222889 ,7287263 ,7351801 ,7416284 ,7480799 ,7545416 ,7609896 ,7674449 ,7739107 ,7803782 ,7868350 ,7933207 ,7997841 ,8062722 ,8127413 ,8192274 ,8257084 ,8321906 ,8386908 ,8451805 ,8516711 ,8581801 ,8646872 ,8712055 ,8776972 ,8842096 ,8907197 ,8972275 ,9037389 ,9102547 ,9167660 ,9232961 ,9298285 ,9363554 ,9428838 ,9494157 ,9559561 ,9625004 ,9690447 ,9755938 ,9821311 ,9886950 ,9952341 ,10017983 ,10083336 ,10148844 ,10214511 ,10280203 ,10345820 ,10411389 ,10477188 ,10542883 ,10608523 ,10674240 ,10740072 ,10805861 ,10871705 ,10937504 ,11003239 ,11069223 ,11135127 ,11201007 ,11266950 ,11332921 ,11398800 ,11464883 ,11531043 ,11597052 ,11663081 ,11729193 ,11795095 ,11861262 ,11927525 ,11993705 ,12059801 ,12126025 ,12192161 ,12258400 ,12324765 ,12391040 ,12457206 ,12523516 ,12589800 ,12656166 ,12722647 ,12789067 ,12855435 ,12921848 ,12988106 ,13054579 ,13120976 ,13187504 ,13253953 ,13320508 ,13387020 ,13453602 ,13520191 ,13586774 ,13653326 ,13719869 ,13786622 ,13853247 ,13919860 ,13986514 ,14053203 ,14120008 ,14186683 ,14253309 ,14320169 ,14386885 ,14453540 ,14520392 ,14587304 ,14654166 ,14721013 ,14788025 ,14854944 ,14921887 ,14988913 ,15055781 ,15122815 ,15189684 ,15256723 ,15323818 ,15390837 ,15457662 ,15524804 ,15591829 ,15658940 ,15726171 ,15793160 ,15860307 ,15927503 ,15994523 ,16061729 ,16128806 ,16196180 ,16263185 ,16330499 ,16397659 ,16465173 ,16532492 ,16599543 ,16666832 ,16734026 ,16801580 ,16868992 ,16936281 ,17003734 ,17071064 ,17138487 ,17205892 ,17273262 ,17340555 ,17408234 ,17475663 ,17543179 ,17610633 ,17678073 ,17745712 ,17813338 ,17880846 ,17948260 ,18015903 ,18083659 ,18151158 ,18218758 ,18286380 ,18354109 ,18421709 ,18489411 ,18557022 ,18624730 ,18692444 ,18760128 ,18827784 ,18895625 ,18963400 ,19031065 ,19098848 ,19166686 ,19234290 ,19302333 ,19370154 ,19437952 ,19505801 ,19573738 ,19641642 ,19709539 ,19777519 ,19845360 ,19913314 ,19981311 ,20049275 ,20117231 ,20185285 ,20253372 ,20321385 ,20389349 ,20457277 ,20525251 ,20593338 ,20661406 ,20729330 ,20797638 ,20865650 ,20933626 ,21001835 ,21070039 ,21138111 ,21206251 ,21274436 ,21342628 ,21410818 ,21478897 ,21547076 ,21615240 ,21683484 ,21751910 ,21820144 ,21888218 ,21956598 ,22024813 ,22093104 ,22161473 ,22229668 ,22298010 ,22366325 ,22434698 ,22503073 ,22571473 ,22639973 ,22708167 ,22776638 ,22844856 ,22913339 ,22981813 ,23050191 ,23118657 ,23187142 ,23255760 ,23324126 ,23392633 ,23461131 ,23529723 ,23598181 ,23666695 ,23735094 ,23803842 ,23872307 ,23940890 ,24009642 ,24078082 ,24146811 ,24215412 ,24283975 ,24352612 ,24421331 ,24489922 ,24558490 ,24627264 ,24695920 ,24764581 ,24833370 ,24902012 ,24970658 ,25039591 ,25108380 ,25177023 ,25245874 ,25314713 ,25383395 ,25452216 ,25520950 ,25589640 ,25658587 ,25727356 ,25796374 ,25864892 ,25933934 ,26002836 ,26071797 ,26140573 ,26209372 ,26278284 ,26347174 ,26416220 ,26485076 ,26553898 ,26622902 ,26691832 ,26760824 ,26829736 ,26898791 ,26967661 ,27036594 ,27105540 ,27174566 ,27243596 ,27312740 ,27381584 ,27450706 ,27519815 ,27588857 ,27658008 ,27726961 ,27796263 ,27865373 ,27934401 ,28003600 ,28072720 ,28141911 ,28211044 ,28280152 ,28349278 ,28418433 ,28487556 ,28556760 ,28625858 ,28695275 ,28764526 ,28833776 ,28902816 ,28972150 ,29041283 ,29110608 ,29179991 ,29249091 ,29318181 ,29387803 ,29457005 ,29526153 ,29595505 ,29664850 ,29734247 ,29803499 ,29872852 ,29942284 ,30011625 ,30080989 ,30150288 ,30219657 ,30289056 ,30358441 ,30427851 ,30497293 ,30566596 ,30636082 ,30705538 ,30775130 ,30844631 ,30914174 ,30983865 ,31053104 ,31122720 ,31192185 ,31261708 ,31331179 ,31400665 ,31470167 ,31539629 ,31609415 ,31678905 ,31748423 ,31818049 ,31887517 ,31957195 ,32026828 ,32096363 ,32165782 ,32235458 ,32305187 ,32374684 ,32444202 ,32514025 ,32583567 ,32653329 ,32723079 ,32792672 ,32862322 ,32931981 ,33001587 ,33071461 ,33141122 ,33210831 ,33280440 ,33350201 ,33420074 ,33489755 ,33559362 ,33629179 ,33698999 ,33768791 ,33838507 ,33908292 ,33978065 ,34047766 ,34117622 ,34187483 ,34257522 ,34327221 ,34397226 ,34466780 ,34536661 ,34606560 ,34676502 ,34746324 ,34816149 ,34886244 ,34956127 ,35025894 ,35095848 ,35165726 ,35235542 ,35305473 ,35375439 ,35445390 ,35515410 ,35585385 ,35655575 ,35725400 ,35795501 ,35865375 ,35935339 ,36005327 ,36075391 ,36145351 ,36215350 ,36285340 ,36355393 ,36425210 ,36495439 ,36565467 ,36635633 ,36705664 ,36775711 ,36845959 ,36916012 ,36986127 ,37056227 ,37126284 ,37196391 ,37266373 ,37336429 ,37406632 ,37476732 ,37546854 ,37617135 ,37687066 ,37757288 ,37827432 ,37897612 ,37967807 ,38038091 ,38108260 ,38178409 ,38248734 ,38318810 ,38389187 ,38459587 ,38529679 ,38599776 ,38670164 ,38740415 ,38810775 ,38881066 ,38951294 ,39021547 ,39091984 ,39162099 ,39232436 ,39302705 ,39373229 ,39443464 ,39513770 ,39584051 ,39654454 ,39724915 ,39795183 ,39865626 ,39935822 ,40006151 ,40076406 ,40146977 ,40217225 ,40287863 ,40358205 ,40428460 ,40499036 ,40569451 ,40639846 ,40710205 ,40780909 ,40851206 ,40921645 ,40992128 ,41062626 ,41133137 ,41203411 ,41274028 ,41344480 ,41415033 ,41485427 ,41555943 ,41626559 ,41696924 ,41767271 ,41837952 ,41908455 ,41978974 ,42049572 ,42120055 ,42190574 ,42261305 ,42331735 ,42402400 ,42473052 ,42543639 ,42614152 ,42684646 ,42755203 ,42825817 ,42896463 ,42967172 ,43037631 ,43108426 ,43178987 ,43249727 ,43320403 ,43390980 ,43461643 ,43532316 ,43603043 ,43673762 ,43744530 ,43814989 ,43885883 ,43956666 ,44027222 ,44097954 ,44168650 ,44239427 ,44310192 ,44380881 ,44451746 ,44522226 ,44593038 ,44663695 ,44734363 ,44805229 ,44876141 ,44946860 ,45017650 ,45088495 ,45159225 ,45230120 ,45300791 ,45371706 ,45442570 ,45513056 ,45584127 ,45654977 ,45725826 ,45796647 ,45867550 ,45938348 ,46009375 ,46080066 ,46150849 ,46221808 ,46292609 ,46363380 ,46434213 ,46505311 ,46576066 ,46647022 ,46718005 ,46788960 ,46859891 ,46930828 ,47001862 ,47072832 ,47143775 ,47214676 ,47285385 ,47356530 ,47427583 ,47498548 ,47569533 ,47640580 ,47711417 ,47782512 ,47853498 ,47924317 ,47995455 ,48066408 ,48137364 ,48208385 ,48279546 ,48350702 ,48421737 ,48492552 ,48563637 ,48634691 ,48705847 ,48776827 ,48847941 ,48919087 ,48990063 ,49061103 ,49132138 ,49203373 ,49274473 ,49345532 ,49416804 ,49487866 ,49558862 ,49630130 ,49701274 ,49772221 ,49843326 ,49914651 ,49985609 ,50056820 ,50128154 ,50199195 ,50270272 ,50341562 ,50412745 ,50483836 ,50555099 ,50626208 ,50697503 ,50768729 ,50839890 ,50911134 ,50982278 ,51053475 ,51124796 ,51195973 ,51267317 ,51338440 ,51409728 ,51480965 ,51552237 ,51623499 ,51694640 ,51765768 ,51837197 ,51908365 ,51979756 ,52051111 ,52122427 ,52193913 ,52265154 ,52336497 ,52407735 ,52479158 ,52550572 ,52621807 ,52693196 ,52764502 ,52835891 ,52907210 ,52978502 ,53049928 ,53121211 ,53192609 ,53264030 ,53335384 ,53406632 ,53478115 ,53549422 ,53621006 ,53692239 ,53763585 ,53835155 ,53906422 ,53977894 ,54049364 ,54120906 ,54192317 ,54263665 ,54335120 ,54406609 ,54478028 ,54549489 ,54620923 ,54692413 ,54763944 ,54835303 ,54906935 ,54978072 ,55049697 ,55121210 ,55192838 ,55264143 ,55335558 ,55407178 ,55478807 ,55550306 ,55621747 ,55693266 ,55764926 ,55836212 ,55907766 ,55979490 ,56050963 ,56122549 ,56194062 ,56265654 ,56337238 ,56408626 ,56480274 ,56551844 ,56623611 ,56695327 ,56766825 ,56838498 ,56909847 ,56981496 ,57053115 ,57124862 ,57196411 ,57267939 ,57339678 ,57411231 ,57482917 ,57554515 ,57626022 ,57697829 ,57769615 ,57841188 ,57912877 ,57984472 ,58056130 ,58128017 ,58199701 ,58271431 ,58343118 ,58414809 ,58486498 ,58558283 ,58629964 ,58701777 ,58773249 ,58845180 ,58916819 ,58988635 ,59060235 ,59131858 ,59203647 ,59275504 ,59347222 ,59418990 ,59490677 ,59562581 ,59634222 ,59706022 ,59777824 ,59849704 ,59921614 ,59993173 ,60064858 ,60136625 ,60208648 ,60280393 ,60352185 ,60424023 ,60495915 ,60567710 ,60639464 ,60711300 ,60783150 ,60854963 ,60926743 ,60998733 ,61070642 ,61142457 ,61214340 ,61286233 ,61357908 ,61429715 ,61501513 ,61573389 ,61645456 ,61717257 ,61789206 ,61861056 ,61932989 ,62004998 ,62076746 ,62148770 ,62220699 ,62292534 ,62364486 ,62436364 ,62508643 ,62580510 ,62652459 ,62724333 ,62796349 ,62868158 ,62940349 ,63012218 ,63084069 ,63156092 ,63228003 ,63300041 ,63372037 ,63444032 ,63515901 ,63588069 ,63660053 ,63731989 ,63803866 ,63876099 ,63947993 ,64019864 ,64092125 ,64164224 ,64236371 ,64308405 ,64380477 ,64452404 ,64524477 ,64596503 ,64668423 ,64740512 ,64812800 ,64884881 ,64956959 ,65028812 ,65100977 ,65173128 ,65245142 ,65317172 ,65389247 ,65461340 ,65533416 ,65605632 ,65677798 ,65749891 ,65821996 ,65894016 ,65966074 ,66038121 ,66110248 ,66182647 ,66254519 ,66327035 ,66399186 ,66471239 ,66543366 ,66615536 ,66687600 ,66759720 ,66831968 ,66904006 ,66976166 ,67048636 ,67120862 ,67192931 ,67265138 ,67337438 ,67409442 ,67481888 ,67554055 ,67626017 ,67698299 ,67770595 ,67842834 ,67914981 ,67987278 ,68059495 ,68131697 ,68203935 ,68276114 ,68348381 ,68420632 ,68492860 ,68565048 ,68637245 ,68709650 ,68781874 ,68854138 ,68926320 ,68998745 ,69071164 ,69143248 ,69215766 ,69287931 ,69360401 ,69432848 ,69505091 ,69577434 ,69649878 ,69721871 ,69794342 ,69866611 ,69938806 ,70011171 ,70083412 ,70155850 ,70228266 ,70300739 ,70373036 ,70445274 ,70517560 ,70589900 ,70662315 ,70734500 ,70806949 ,70879371 ,70951804 ,71024209 ,71096526 ,71169053 ,71241374 ,71313725 ,71386192 ,71458556 ,71530697 ,71603102 ,71675739 ,71748132 ,71820624 ,71892983 ,71965396 ,72037927 ,72110314 ,72182729 ,72255314 ,72327796 ,72400186 ,72472554 ,72544965 ,72617625 ,72689816 ,72762388 ,72834872 ,72907273 ,72979802 ,73052262 ,73124539 ,73197094 ,73269544 ,73342116 ,73414500 ,73486968 ,73559651 ,73632087 ,73704751 ,73777177 ,73849759 ,73922188 ,73994847 ,74067536 ,74139997 ,74212464 ,74285086 ,74357683 ,74430312 ,74502745 ,74575198 ,74647861 ,74720464 ,74792963 ,74865657 ,74938225 ,75010654 ,75083101 ,75155792 ,75228316 ,75300844 ,75373591 ,75446102 ,75518697 ,75591190 ,75663847 ,75736411 ,75809049 ,75881609 ,75954194 ,76026880 ,76099535 ,76172094 ,76244754 ,76317384 ,76389994 ,76462769 ,76535454 ,76607881 ,76680808 ,76753225 ,76826046 ,76898537 ,76971173 ,77043897 ,77116510 ,77189329 ,77262002 ,77334573 ,77407256 ,77480091 ,77552719 ,77625409 ,77698216 ,77770734 ,77843549 ,77916212 ,77988837 ,78061672 ,78134416 ,78207051 ,78279838 ,78352522 ,78425266 ,78498055 ,78570584 ,78643369 ,78716167 ,78788958 ,78861744 ,78934458 ,79007245 ,79079662 ,79152529 ,79225162 ,79297939 ,79370790 ,79443646 ,79516308 ,79589033 ,79661766 ,79734777 ,79807700 ,79880557 ,79953492 ,80026238 ,80098985 ,80171764 ,80244564 ,80317482 ,80390346 ,80462978 ,80535799 ,80608676 ,80681727 ,80754466 ,80827392 ,80900032 ,80972969 ,81045697 ,81118611 ,81191446 ,81264355 ,81337211 ,81410157 ,81482872 ,81555719 ,81628645 ,81701541 ,81774614 ,81847425 ,81920283 ,81993077 ,82065982 ,82139051 ,82211988 ,82284708 ,82357839 ,82430568 ,82503598 ,82576583 ,82649359 ,82722391 ,82795201 ,82868156 ,82941043 ,83014088 ,83086965 ,83159825 ,83232548 ,83305713 ,83378618 ,83451670 ,83524496 ,83597481 ,83670649 ,83743616 ,83816563 ,83889505 ,83962307 ,84035376 ,84108420 ,84181419 ,84254311 ,84327139 ,84400044 ,84473158 ,84546074 ,84619264 ,84692417 ,84765314 ,84838331 ,84911284 ,84984096 ,85057369 ,85130278 ,85203049 ,85276199 ,85349009 ,85422241 ,85495346 ,85568254 ,85641120 ,85714239 ,85787172 ,85860209 ,85933415 ,86006640 ,86079697 ,86152578 ,86225470 ,86298624 ,86371676 ,86444891 ,86518027 ,86590933 ,86663889 ,86737044 ,86810362 ,86883323 ,86956368 ,87029555 ,87102560 ,87175481 ,87248668 ,87321800 ,87394799 ,87467829 ,87540926 ,87614118 ,87687171 ,87760320 ,87833572 ,87906638 ,87979727 ,88052921 ,88126023 ,88199162 ,88272417 ,88345588 ,88418747 ,88491708 ,88564985 ,88638118 ,88711336 ,88784453 ,88857679 ,88930771 ,89004013 ,89077151 ,89150554 ,89223711 ,89296927 ,89370147 ,89443424 ,89516702 ,89589736 ,89662872 ,89736071 ,89809334 ,89882437 ,89955806 ,90029039 ,90102144 ,90175399 ,90248608 ,90321909 ,90395246 ,90468447 ,90541384 ,90614716 ,90687905 ,90760995 ,90834558 ,90907548 ,90980808 ,91054149 ,91127436 ,91200600 ,91274122 ,91347095 ,91420449 ,91493759 ,91567149 ,91640346 ,91713580 ,91787011 ,91860200 ,91933523 ,92006758 ,92080105 ,92153454 ,92226833 ,92300126 ,92373323 ,92446616 ,92519712 ,92593107 ,92666520 ,92739781 ,92813156 ,92886382 ,92959815 ,93033160 ,93106562 ,93179983 ,93253209 ,93326521 ,93399832 ,93473157 ,93546575 ,93620081 ,93693312 ,93766590 ,93840058 ,93913377 ,93986647 ,94060017 ,94133465 ,94206877 ,94279981 ,94353584 ,94426928 ,94500093 ,94573504 ,94647161 ,94720480 ,94793799 ,94867402 ,94940822 ,95014187 ,95087544 ,95160901 ,95234464 ,95307803 ,95381357 ,95454681 ,95528286 ,95601629 ,95674913 ,95748414 ,95821893 ,95895160 ,95968753 ,96042080 ,96115545 ,96188974 ,96262289 ,96335662 ,96409162 ,96482570 ,96556143 ,96629617 ,96703028 ,96776439 ,96850035 ,96923511 ,96997002 ,97070517 ,97143964 ,97217335 ,97290774 ,97364285 ,97437883 ,97511212 ,97584945 ,97658476 ,97731999 ,97805274 ,97878973 ,97952518 ,98025999 ,98099368 ,98172713 ,98246503 ,98319931 ,98393571 ,98467044 ,98540673 ,98614361 ,98688026 ,98761451 ,98834994 ,98908552 ,98981999 ,99055416 ,99128969 ,99202624 ,99276151 ,99349772 ,99423246 ,99496636 ,99570315 ,99643973 ,99717528 ,99791181 ,99864778 ,99938273 ,100011878 ,100085415 ,100159132 ,100232793 ,100306278 ,100379804 ,100453513 ,100527100 ,100600649 ,100674252 ,100747901 ,100821582 ,100895222 ,100968619 ,101042400 ,101115933 ,101189506 ,101263187 ,101336784 ,101410246 ,101483929 ,101557578 ,101631373 ,101705008 ,101778457 ,101852122 ,101925751 ,101999356 ,102073059 ,102146913 ,102220718 ,102294429 ,102368031 ,102441574 ,102515333 ,102588905 ,102662725 ,102736154 ,102809928 ,102883573 ,102957272 ,103031064 ,103104709 ,103178493 ,103251989 ,103325674 ,103399425 ,103473095 ,103546790 ,103620580 ,103694382 ,103767815 ,103841727 ,103915454 ,103988991 ,104062960 ,104136533 ,104210246 ,104283935 ,104357668 ,104431236 ,104505191 ,104578824 ,104652465 ,104726122 ,104799939 ,104873724 ,104947458 ,105021212 ,105094758 ,105168792 ,105242526 ,105316292 ,105390106 ,105463818 ,105537534 ,105611298 ,105685211 ,105758811 ,105832766 ,105906687 ,105980239 ,106054072 ,106127850 ,106201502 ,106275479 ,106349348 ,106423263 ,106496909 ,106570618 ,106644389 ,106718078 ,106792039 ,106865990 ,106939463 ,107013379 ,107087418 ,107161174 ,107235042 ,107308707 ,107382497 ,107456349 ,107530447 ,107604179 ,107678112 ,107751958 ,107825754 ,107899605 ,107973423 ,108047213 ,108121213 ,108194934 ,108268677 ,108342712 ,108416403 ,108490440 ,108564298 ,108638203 ,108712036 ,108785759 ,108859656 ,108933593 ,109007515 ,109081468 ,109155287 ,109229063 ,109303118 ,109377036 ,109450816 ,109524765 ,109598631 ,109672495 ,109746374 ,109820393 ,109894450 ,109968295 ,110042126 ,110116161 ,110190128 ,110264063 ,110337888 ,110412050 ,110485790 ,110559823 ,110633827 ,110707725 ,110781732 ,110855570 ,110929629 ,111003608 ,111077400 ,111151301 ,111225457 ,111299408 ,111373275 ,111447224 ,111521099 ,111595251 ,111669309 ,111743115 ,111816923 ,111890732 ,111964886 ,112038784 ,112112756 ,112186735 ,112260902 ,112334773 ,112408674 ,112482705 ,112556756 ,112630659 ,112704648 ,112778820 ,112852965 ,112926930 ,113000990 ,113074903 ,113149045 ,113222949 ,113296984 ,113371030 ,113445163 ,113519266 ,113593044 ,113667319 ,113741130 ,113815127 ,113889111 ,113963461 ,114037364 ,114111405 ,114185383 ,114259458 ,114333552 ,114407554 ,114481623 ,114555948 ,114629727 ,114703918 ,114778131 ,114851906 ,114926004 ,114999975 ,115074254 ,115148380 ,115222475 ,115296384 ,115370490 ,115444677 ,115518777 ,115592864 ,115666881 ,115741084 ,115815383 ,115889166 ,115963167 ,116037255 ,116111417 ,116185551 ,116259756 ,116333832 ,116408069 ,116482178 ,116556424 ,116630435 ,116704606 ,116778605 ,116852718 ,116926939 ,117000987 ,117075173 ,117149279 ,117223337 ,117297603 ,117371600 ,117445777 ,117520084 ,117594155 ,117668315 ,117742580 ,117816531 ,117890738 ,117965073 ,118039119 ,118113226 ,118187333 ,118261589 ,118335620 ,118409893 ,118484214 ,118558409 ,118632346 ,118706805 ,118780991 ,118854963 ,118929355 ,119003413 ,119077526 ,119151813 ,119226048 ,119300114 ,119374466 ,119448511 ,119522708 ,119596893 ,119671202 ,119745484 ,119819637 ,119893760 ,119968076 ,120042420 ,120116479 ,120190538 ,120264841 ,120339200 ,120413536 ,120487438 ,120561836 ,120636335 ,120710579 ,120784764 ,120859009 ,120933108 ,121007251 ,121081536 ,121155761 ,121229979 ,121304229 ,121378410 ,121452646 ,121527010 ,121601388 ,121675769 ,121750264 ,121824287 ,121898492 ,121972670 ,122047095 ,122121352 ,122195644 ,122270133 ,122344498 ,122418781 ,122493103 ,122567412 ,122641650 ,122715770 ,122790178 ,122864439 ,122939061 ,123013342 ,123087597 ,123161687 ,123236160 ,123310455 ,123384892 ,123459262 ,123533498 ,123607937 ,123682061 ,123756357 ,123830688 ,123904959 ,123979412 ,124053749 ,124128068 ,124202370 ,124276781 ,124351348 ,124425510 ,124499721 ,124574112 ,124648565 ,124722684 ,124797055 ,124871441 ,124945875 ,125020203 ,125094613 ,125169077 ,125243298 ,125317851 ,125392268 ,125466619 ,125541125 ,125615584 ,125689768 ,125764189 ,125838415 ,125912765 ,125987181 ,126061638 ,126136179 ,126210539 ,126284954 ,126359451 ,126433879 ,126508334 ,126582686 ,126657111 ,126731306 ,126805807 ,126880367 ,126954773 ,127029238 ,127103675 ,127178359 ,127252670 ,127326887 ,127401320 ,127475516 ,127549874 ,127624443 ,127699135 ,127773478 ,127847998 ,127922523 ,127996824 ,128071185 ,128145606 ,128220210 ,128294814 ,128369194 ,128443592 ,128518097 ,128592492 ,128666966 ,128741446 ,128815861 ,128890260 ,128964836 ,129039337 ,129113782 ,129188435 ,129262728 ,129337117 ,129411579 ,129486083 ,129560464 ,129635216 ,129709890 ,129784401 ,129858844 ,129933403 ,130007765 ,130082371 ,130156744 ,130231384 ,130305949 ,130380478 ,130454797 ,130529473 ,130603970 ,130678587 ,130753047 ,130827454 ,130902013 ,130976748 ,131051141 ,131125699 ,131200246 ,131274788 ,131349277 ,131423898 ,131498403 ,131573024 ,131647575 ,131722043 ,131796683 ,131871464 ,131945984 ,132020334 ,132095101 ,132169422 ,132243983 ,132318553 ,132392959 ,132467744 ,132542420 ,132617074 ,132691487 ,132765986 ,132840590 ,132915061 ,132989730 ,133064406 ,133138967 ,133213696 ,133288266 ,133362687 ,133437247 ,133511852 ,133586542 ,133661203 ,133735904 ,133810301 ,133885114 ,133959845 ,134034243 ,134108837 ,134183194 ,134257862 ,134332619 ,134407214 ,134482155 ,134556904 ,134631328 ,134705951 ,134780630 ,134855217 ,134929725 ,135004398 ,135079057 ,135153735 ,135228557 ,135303074 ,135377685 ,135452354 ,135527073 ,135601752 ,135676226 ,135751061 ,135825639 ,135900389 ,135974916 ,136049517 ,136124126 ,136199006 ,136273533 ,136348140 ,136422830 ,136497675 ,136572346 ,136647031 ,136721579 ,136796404 ,136870983 ,136945660 ,137020541 ,137095077 ,137169730 ,137244442 ,137319261 ,137393928 ,137468575 ,137543343 ,137618056 ,137692717 ,137767667 ,137842258 ,137916975 ,137991738 ,138066435 ,138141181 ,138215842 ,138290498 ,138365223 ,138440042 ,138514567 ,138589350 ,138664168 ,138739028 ,138813652 ,138888561 ,138963046 ,139037893 ,139112701 ,139187666 ,139262321 ,139336947 ,139411658 ,139486443 ,139561398 ,139635966 ,139710957 ,139785483 ,139860469 ,139935095 ,140009932 ,140084489 ,140159383 ,140234052 ,140308623 ,140383592 ,140458283 ,140533043 ,140607936 ,140682910 ,140757535 ,140832471 ,140907216 ,140982029 ,141056924 ,141131464 ,141206196 ,141281075 ,141356002 ,141430788 ,141505504 ,141580308 ,141655103 ,141730079 ,141804948 ,141879805 ,141954344 ,142029124 ,142103989 ,142178867 ,142253693 ,
};

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		int aa=N/10000;
		long long res=a[aa];

		for(int i=aa*10000+1;i<=N;++i){
			long long base=1;
			int t=i,flag=0;
			for(int j=2;j*j<=t;++j){
				int cnt=0;
				while(t&&t%j==0){
					++cnt;
					t/=j;
				}
				if(cnt>=3){
					flag=1;
					break;
				}else if(cnt==1)base*=2;
			}
			if(t>=2)base*=2;
			if(!flag)res+=base;
		}
		printf("%lld\n",res);
	}
	return 0;
}
