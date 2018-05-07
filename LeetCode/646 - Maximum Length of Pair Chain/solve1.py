class Solution:
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        pairs = sorted(pairs)
        N = len(pairs)
        dp = [0] * N
        
        for i in range(N):
            cur = pairs[i]
            # d = cur[1] - cur[0]
            d = 1
            dp[i] = max(dp[i], d)
            
            for k in range(i+1, N):
                next = pairs[k]
                if next[0] > cur[1]:
                    # dp[k] = max(dp[k], dp[i] + next[1]-next[0])
                    dp[k] = max(dp[k], dp[i] + 1)

        return dp[-1]

s = Solution()
print(s.findLongestChain([[-188,-112],[-407,885],[-678,-171],[-571,474],[202,393],[408,525],[-730,-435],[791,908],[138,306],[727,780],[-220,794],[-410,953],[-27,859],[-337,545],[-1,860],[-651,717],[-2,548],[384,975],[-322,176],[-913,782],[824,930],[570,806],[650,880],[-807,-468],[226,626],[-777,671],[744,901],[291,529],[-270,187],[961,995],[73,114],[-455,117],[-535,655],[-150,372],[-586,292],[973,999],[-216,508],[-742,734],[-263,970],[170,855],[314,459],[922,953],[-501,438],[-81,275],[-609,848],[548,952],[-509,-448],[490,771],[577,638],[-961,-398],[924,975],[121,245],[-351,216],[753,1000],[525,797],[199,851],[-772,588],[-414,-5],[405,694],[-560,704],[-248,245],[918,995],[-230,881],[-824,88],[728,860],[375,1000],[-599,-34],[870,883],[-613,-256],[771,980],[-633,-330],[222,891],[533,842],[402,406],[-276,56],[846,889],[949,995],[-321,658],[-213,351],[-800,-225],[547,874],[926,993],[860,895],[-862,737],[-654,-36],[557,954],[346,938],[-622,257],[315,656],[873,937],[-731,139],[-40,927],[-452,-435],[-835,792],[962,963],[37,679],[476,696],[443,563],[547,663],[963,986],[26,502],[-162,128],[656,724],[-707,-316],[168,423],[684,910],[582,795],[-17,-6],[-117,951],[890,949],[700,890],[309,413],[449,673],[-653,941],[658,972],[-843,553],[-166,545],[507,515],[651,729],[-470,374],[18,903],[768,822],[-683,941],[-946,551],[-838,591],[-59,19],[-994,817],[-214,103],[-59,204],[920,993],[-390,798],[-585,-162],[370,569],[562,817],[-608,-495],[-641,805],[-222,342],[167,903],[678,702],[485,734],[851,915],[277,363],[497,756],[821,860],[-266,-9],[-66,823],[-752,408],[-45,513],[-893,183],[-80,200],[234,768],[-585,-558],[-161,679],[993,998],[384,599],[-389,566],[-657,-406],[593,871],[-686,-471],[876,913],[-670,531],[-934,759],[-148,603],[-641,182],[-297,229],[-828,-231],[-996,-869],[-55,665],[-836,673],[315,915],[-564,668],[125,983],[622,711],[472,687],[919,974],[303,996],[-124,282],[-844,-764],[599,629],[-653,-440],[-761,993],[-372,404],[-984,-372],[-101,121],[728,944],[292,941],[-244,726],[379,941],[76,465],[709,717],[718,794],[-113,455],[878,887],[-940,-748],[-180,362],[11,134],[-473,349],[-405,300],[-776,947],[165,480],[116,353],[-906,713],[-1000,-222],[-999,-168],[-355,45],[827,896],[377,889],[-277,500],[276,738],[292,570],[211,924],[-358,-4],[597,717],[-542,-210],[356,800],[-536,224],[565,710],[-144,591],[866,873],[-767,450],[582,938],[-127,-23],[593,888],[-172,730],[-294,-130],[-101,90],[-809,324],[511,750],[-717,-490],[156,618],[-439,-194],[-662,-600],[-964,-28],[-132,395],[-945,710],[511,688],[545,677],[-28,676],[544,753],[2,135],[524,848],[44,651],[-925,230],[703,998],[797,880],[591,752],[-743,269],[435,696],[602,878],[-512,-188],[-152,-48],[-987,-118],[416,939],[204,728],[356,923],[625,933],[597,773],[-411,-39],[-480,80],[-892,-740],[-523,-92],[-456,36],[-968,669],[621,798],[-228,887],[-357,174],[156,508],[-473,650],[276,567],[703,949],[61,987],[985,987],[758,963],[-476,-472],[775,928],[-240,982],[-230,281],[-339,129],[498,854],[-184,742],[-732,749],[-652,-66],[-785,-141],[-301,46],[-747,-510],[43,573],[-719,-551],[787,970],[-497,962],[617,638],[359,454],[-36,635],[259,476],[-81,-66],[356,803],[-606,847],[-701,125],[-975,-4],[-143,817],[-783,55],[-786,200],[350,791],[282,393],[-120,888],[-11,85],[-163,424],[-803,375],[-144,323],[171,570],[926,985],[499,756],[508,812],[951,968],[176,970],[860,893],[656,706],[109,733],[-355,270],[-989,-637],[-147,969],[-477,491],[-255,901],[-835,-404],[270,874],[-127,595],[-947,-904],[-216,571],[-96,78],[323,564],[-579,751],[799,977],[584,616],[-560,930],[-705,755],[-314,329],[697,852],[296,614],[-115,210],[158,581],[-533,-523],[790,791],[-830,405],[568,588],[-643,81],[136,173],[837,951],[736,967],[809,933],[515,953],[-459,-40],[101,642],[-777,646],[826,925],[-36,629],[670,877],[-353,673],[-714,443],[844,923],[-642,357],[536,911],[351,482],[667,880],[587,791],[400,448],[522,969],[840,959],[-302,748],[-280,807],[944,954],[628,983],[-605,529],[-654,374],[-444,36],[-806,917],[-933,938],[-220,-48],[-399,441],[-792,569],[674,792],[-705,-543],[22,853],[-861,-603],[24,463],[973,984],[100,382],[73,286],[-534,842],[-488,344],[-622,626],[-641,128],[-461,-452],[-209,377],[613,807],[189,851],[728,855],[883,930],[-288,60],[-969,497],[-864,-704],[283,627],[-616,-197],[663,927],[466,483],[-466,-176],[-23,572],[-377,489],[-20,305],[347,631],[202,785],[741,921],[165,512],[185,889],[357,884],[789,942],[515,520],[596,783],[685,788],[573,941],[-635,-19],[-284,53],[616,701],[-943,270],[79,362],[-495,770],[858,878],[112,352],[701,827],[-776,-130],[46,431],[-220,866],[397,544],[455,623],[533,936],[302,654],[-46,483],[-531,-447],[113,187],[844,923],[-132,599],[-534,557],[9,466],[336,909],[-478,-204],[-439,-370],[44,546],[720,761],[471,879],[20,624],[-989,-590],[-422,805],[862,963],[-276,567],[803,994],[488,601],[246,660],[-979,-521],[-217,941],[832,934],[-977,254],[-250,478],[95,391],[543,650],[-52,363],[617,810],[641,807],[204,437],[-454,976],[442,981],[394,684],[-464,-435],[699,765],[-814,609],[333,656],[522,689],[-100,658],[-787,-772],[-350,435],[302,584],[-701,188],[155,528],[340,766],[175,488],[104,364],[-860,-260],[714,875],[-459,259],[762,949],[-400,638],[-210,623],[441,657],[-230,-85],[2,107],[-910,-419],[-823,-650],[-583,544],[-442,154],[876,946],[771,816],[-567,314],[-693,-259],[-324,340],[139,299],[780,828],[456,766],[330,852],[745,789],[529,599],[659,842],[-338,-214],[-990,-827],[868,929],[-254,-200],[-628,650],[-366,578],[35,321],[-600,-297],[11,566],[420,822],[63,795],[-675,90],[-481,561],[-950,-541],[-829,-199],[-669,587],[-315,75],[598,805],[63,254],[-169,-40],[836,846],[48,985],[152,237],[-460,885],[-623,317],[-448,-65],[79,467],[505,567],[-597,131],[-757,-437],[-218,103],[276,434],[545,660],[558,826],[-90,658],[-304,752],[554,577],[98,893],[-998,-569],[-698,398],[79,302],[256,503],[-753,667],[339,929],[140,579],[-500,-6],[379,910],[-63,428],[143,410],[31,788],[-633,-64],[575,671],[-808,275],[-889,-390],[-166,766],[975,976],[719,847],[-53,240],[267,998],[-879,701],[497,755],[-917,-732],[-780,133],[-601,-181],[704,725],[331,427],[565,670],[370,786],[-157,958],[-920,445],[429,911],[-678,262],[-32,251],[-54,354],[20,541],[718,731],[785,977],[-307,941],[-549,402],[962,986],[376,760],[-317,130],[-715,-330],[-737,634],[983,992],[674,880],[-974,218],[136,162],[-52,420],[-849,-124],[-617,307],[38,387],[-12,488],[216,904],[-301,234],[-963,-734],[795,870],[609,744],[-970,924],[309,462],[866,982],[305,569],[145,797],[795,848],[-541,457],[-184,575],[121,594],[391,536],[-622,568],[970,993],[164,472],[399,967],[-817,-81],[-526,626],[-697,112],[-421,-357],[-152,445],[-134,770],[-652,708],[-298,560],[-850,-158],[-150,906],[8,897],[-313,800],[-595,341],[228,272],[-546,-30],[585,682],[-888,835],[121,618],[345,978],[560,755],[583,649],[897,967],[-268,81],[-954,-757],[-720,527],[-295,-221],[-773,640],[-879,-259],[-519,-501],[17,814],[-562,-429],[-292,204],[-585,293],[566,908],[144,606],[489,949],[588,821],[-385,652],[165,633],[973,982],[817,842],[-241,622],[954,959],[-400,70],[418,543],[681,754],[554,686],[-780,628],[-769,446],[859,907],[-6,623],[-726,782],[516,871],[-24,115],[889,941],[-1000,153],[633,751],[553,809],[494,770],[-253,427],[-234,-57],[-376,868],[663,711],[482,838],[119,907],[-65,387],[-333,767],[80,853],[-746,-99],[-37,-32],[653,949],[86,430],[-694,-634],[-627,647],[13,618],[-526,-421],[872,959],[346,495],[15,499],[909,973],[218,430],[-250,513],[-332,475],[-73,812],[297,958],[303,532],[-602,-421],[-168,954],[-646,505],[707,832],[-748,-3],[-265,467],[664,915],[-417,-123],[93,649],[95,270],[-933,439],[-449,-234],[451,785],[671,730],[-264,50],[-84,58],[930,975],[675,816],[-70,871],[423,572],[-120,98],[452,455],[606,925],[433,514],[-530,-316],[-101,837],[773,926],[-356,-199],[-949,912],[936,971],[-519,655],[-718,-36],[73,417],[-929,-495],[291,449],[770,990],[434,804],[202,682],[-928,-434],[580,607],[571,677],[529,718],[91,991],[-995,628],[430,774],[-335,700],[-302,362],[945,954],[192,538],[-885,-126],[890,945],[421,952],[-387,596],[817,919],[813,978],[-952,817],[760,983],[-534,205],[344,393],[-596,-300],[210,348],[879,963],[-794,550],[783,920],[-664,-59],[794,861],[673,894],[-998,127],[-568,942],[287,950],[598,729],[-295,583],[94,605],[91,995],[-900,-128],[472,745],[802,834],[-714,-260],[18,616],[-229,-175],[759,883],[823,880],[-140,36],[-557,73],[929,975],[-305,501],[579,920],[633,819],[609,755],[-33,145],[-582,864],[404,924],[-338,667],[-677,628],[-333,914],[-143,-59],[-745,-734],[161,629],[588,993],[-26,869],[768,797],[-751,961],[-806,-32],[-352,-167],[599,832],[-734,-334],[428,432],[8,190],[-278,-188],[747,978],[-699,-45],[63,732],[261,405],[-466,-361],[-148,211],[-411,759],[-590,-498],[-896,17],[-723,-105],[-438,658],[317,722],[-547,562],[457,967],[-86,-30],[-326,-124],[-236,-162],[277,858],[-144,6],[611,832],[815,841],[-412,-386],[-371,168],[-380,663],[-137,234],[-410,187],[-902,104],[-287,737],[-632,176],[-610,659],[831,974],[-841,-534],[-354,-116],[-819,-200],[574,784],[-644,-368],[-516,300],[962,989],[250,857],[-200,188],[-894,457],[-555,-224],[-165,24],[767,918],[-751,-393],[-130,-13],[893,969],[668,753],[-168,611],[-963,129],[-831,876],[-663,40],[875,905],[-707,980],[-212,244],[-152,953],[-523,744],[119,842],[367,696],[864,993],[187,961],[225,264],[412,645],[92,143],[513,742],[889,913],[-357,691],[-464,482],[104,934],[-516,-310],[132,971],[-325,-210],[958,973],[-52,760],[-61,443],[915,926],[-209,922],[132,338],[-126,494],[250,355],[802,860],[858,998],[-641,-210],[739,921]]))
