/****************************************************************************
** Meta object code from reading C++ file 'qg_actionhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../librecad/src/ui/qg_actionhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qg_actionhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QG_ActionHandler_t {
    QByteArrayData data[173];
    char stringdata0[3040];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QG_ActionHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QG_ActionHandler_t qt_meta_stringdata_QG_ActionHandler = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QG_ActionHandler"
QT_MOC_LITERAL(1, 17, 19), // "slotFileNewTemplate"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "slotFileOpen"
QT_MOC_LITERAL(4, 51, 14), // "slotFileSaveAs"
QT_MOC_LITERAL(5, 66, 22), // "slotFileExportMakerCam"
QT_MOC_LITERAL(6, 89, 10), // "slotZoomIn"
QT_MOC_LITERAL(7, 100, 11), // "slotZoomOut"
QT_MOC_LITERAL(8, 112, 12), // "slotZoomAuto"
QT_MOC_LITERAL(9, 125, 14), // "slotZoomWindow"
QT_MOC_LITERAL(10, 140, 11), // "slotZoomPan"
QT_MOC_LITERAL(11, 152, 16), // "slotZoomPrevious"
QT_MOC_LITERAL(12, 169, 14), // "slotZoomRedraw"
QT_MOC_LITERAL(13, 184, 28), // "slotToolRegenerateDimensions"
QT_MOC_LITERAL(14, 213, 22), // "slotEditKillAllActions"
QT_MOC_LITERAL(15, 236, 12), // "slotEditUndo"
QT_MOC_LITERAL(16, 249, 12), // "slotEditRedo"
QT_MOC_LITERAL(17, 262, 11), // "slotEditCut"
QT_MOC_LITERAL(18, 274, 12), // "slotEditCopy"
QT_MOC_LITERAL(19, 287, 13), // "slotEditPaste"
QT_MOC_LITERAL(20, 301, 15), // "slotOrderBottom"
QT_MOC_LITERAL(21, 317, 14), // "slotOrderLower"
QT_MOC_LITERAL(22, 332, 14), // "slotOrderRaise"
QT_MOC_LITERAL(23, 347, 12), // "slotOrderTop"
QT_MOC_LITERAL(24, 360, 16), // "slotSelectSingle"
QT_MOC_LITERAL(25, 377, 17), // "slotSelectContour"
QT_MOC_LITERAL(26, 395, 16), // "slotSelectWindow"
QT_MOC_LITERAL(27, 412, 18), // "slotDeselectWindow"
QT_MOC_LITERAL(28, 431, 13), // "slotSelectAll"
QT_MOC_LITERAL(29, 445, 15), // "slotDeselectAll"
QT_MOC_LITERAL(30, 461, 16), // "slotSelectInvert"
QT_MOC_LITERAL(31, 478, 21), // "slotSelectIntersected"
QT_MOC_LITERAL(32, 500, 23), // "slotDeselectIntersected"
QT_MOC_LITERAL(33, 524, 15), // "slotSelectLayer"
QT_MOC_LITERAL(34, 540, 13), // "slotDrawPoint"
QT_MOC_LITERAL(35, 554, 12), // "slotDrawLine"
QT_MOC_LITERAL(36, 567, 17), // "slotDrawLineAngle"
QT_MOC_LITERAL(37, 585, 22), // "slotDrawLineHorizontal"
QT_MOC_LITERAL(38, 608, 20), // "slotDrawLineVertical"
QT_MOC_LITERAL(39, 629, 16), // "slotDrawLineFree"
QT_MOC_LITERAL(40, 646, 19), // "slotDrawLineHorVert"
QT_MOC_LITERAL(41, 666, 20), // "slotDrawLineParallel"
QT_MOC_LITERAL(42, 687, 27), // "slotDrawLineParallelThrough"
QT_MOC_LITERAL(43, 715, 21), // "slotDrawLineRectangle"
QT_MOC_LITERAL(44, 737, 20), // "slotDrawLineBisector"
QT_MOC_LITERAL(45, 758, 20), // "slotDrawLineTangent1"
QT_MOC_LITERAL(46, 779, 20), // "slotDrawLineTangent2"
QT_MOC_LITERAL(47, 800, 22), // "slotDrawLineOrthogonal"
QT_MOC_LITERAL(48, 823, 19), // "slotDrawLineOrthTan"
QT_MOC_LITERAL(49, 843, 20), // "slotDrawLineRelAngle"
QT_MOC_LITERAL(50, 864, 19), // "slotDrawLinePolygon"
QT_MOC_LITERAL(51, 884, 20), // "slotDrawLinePolygon2"
QT_MOC_LITERAL(52, 905, 20), // "slotDrawLinePolygon3"
QT_MOC_LITERAL(53, 926, 14), // "slotDrawCircle"
QT_MOC_LITERAL(54, 941, 16), // "slotDrawCircleCR"
QT_MOC_LITERAL(55, 958, 16), // "slotDrawCircle2P"
QT_MOC_LITERAL(56, 975, 17), // "slotDrawCircle2PR"
QT_MOC_LITERAL(57, 993, 16), // "slotDrawCircle3P"
QT_MOC_LITERAL(58, 1010, 22), // "slotDrawCircleParallel"
QT_MOC_LITERAL(59, 1033, 22), // "slotDrawCircleInscribe"
QT_MOC_LITERAL(60, 1056, 18), // "slotDrawCircleTan2"
QT_MOC_LITERAL(61, 1075, 18), // "slotDrawCircleTan3"
QT_MOC_LITERAL(62, 1094, 21), // "slotDrawCircleTan1_2P"
QT_MOC_LITERAL(63, 1116, 21), // "slotDrawCircleTan2_1P"
QT_MOC_LITERAL(64, 1138, 11), // "slotDrawArc"
QT_MOC_LITERAL(65, 1150, 13), // "slotDrawArc3P"
QT_MOC_LITERAL(66, 1164, 19), // "slotDrawArcParallel"
QT_MOC_LITERAL(67, 1184, 21), // "slotDrawArcTangential"
QT_MOC_LITERAL(68, 1206, 19), // "slotDrawEllipseAxis"
QT_MOC_LITERAL(69, 1226, 22), // "slotDrawEllipseArcAxis"
QT_MOC_LITERAL(70, 1249, 24), // "slotDrawEllipseFociPoint"
QT_MOC_LITERAL(71, 1274, 22), // "slotDrawEllipse4Points"
QT_MOC_LITERAL(72, 1297, 28), // "slotDrawEllipseCenter3Points"
QT_MOC_LITERAL(73, 1326, 23), // "slotDrawEllipseInscribe"
QT_MOC_LITERAL(74, 1350, 14), // "slotDrawSpline"
QT_MOC_LITERAL(75, 1365, 20), // "slotDrawSplinePoints"
QT_MOC_LITERAL(76, 1386, 13), // "slotDrawMText"
QT_MOC_LITERAL(77, 1400, 12), // "slotDrawText"
QT_MOC_LITERAL(78, 1413, 13), // "slotDrawHatch"
QT_MOC_LITERAL(79, 1427, 13), // "slotDrawImage"
QT_MOC_LITERAL(80, 1441, 16), // "slotDrawPolyline"
QT_MOC_LITERAL(81, 1458, 15), // "slotPolylineAdd"
QT_MOC_LITERAL(82, 1474, 18), // "slotPolylineAppend"
QT_MOC_LITERAL(83, 1493, 15), // "slotPolylineDel"
QT_MOC_LITERAL(84, 1509, 22), // "slotPolylineDelBetween"
QT_MOC_LITERAL(85, 1532, 16), // "slotPolylineTrim"
QT_MOC_LITERAL(86, 1549, 23), // "slotPolylineEquidistant"
QT_MOC_LITERAL(87, 1573, 19), // "slotPolylineSegment"
QT_MOC_LITERAL(88, 1593, 14), // "slotDimAligned"
QT_MOC_LITERAL(89, 1608, 13), // "slotDimLinear"
QT_MOC_LITERAL(90, 1622, 16), // "slotDimLinearHor"
QT_MOC_LITERAL(91, 1639, 16), // "slotDimLinearVer"
QT_MOC_LITERAL(92, 1656, 13), // "slotDimRadial"
QT_MOC_LITERAL(93, 1670, 16), // "slotDimDiametric"
QT_MOC_LITERAL(94, 1687, 14), // "slotDimAngular"
QT_MOC_LITERAL(95, 1702, 13), // "slotDimLeader"
QT_MOC_LITERAL(96, 1716, 20), // "slotModifyAttributes"
QT_MOC_LITERAL(97, 1737, 16), // "slotModifyDelete"
QT_MOC_LITERAL(98, 1754, 21), // "slotModifyDeleteQuick"
QT_MOC_LITERAL(99, 1776, 20), // "slotModifyDeleteFree"
QT_MOC_LITERAL(100, 1797, 14), // "slotModifyMove"
QT_MOC_LITERAL(101, 1812, 15), // "slotModifyScale"
QT_MOC_LITERAL(102, 1828, 25), // "slotModifyRevertDirection"
QT_MOC_LITERAL(103, 1854, 16), // "slotModifyRotate"
QT_MOC_LITERAL(104, 1871, 16), // "slotModifyMirror"
QT_MOC_LITERAL(105, 1888, 20), // "slotModifyMoveRotate"
QT_MOC_LITERAL(106, 1909, 17), // "slotModifyRotate2"
QT_MOC_LITERAL(107, 1927, 16), // "slotModifyEntity"
QT_MOC_LITERAL(108, 1944, 14), // "slotModifyTrim"
QT_MOC_LITERAL(109, 1959, 15), // "slotModifyTrim2"
QT_MOC_LITERAL(110, 1975, 20), // "slotModifyTrimAmount"
QT_MOC_LITERAL(111, 1996, 13), // "slotModifyCut"
QT_MOC_LITERAL(112, 2010, 17), // "slotModifyStretch"
QT_MOC_LITERAL(113, 2028, 15), // "slotModifyBevel"
QT_MOC_LITERAL(114, 2044, 15), // "slotModifyRound"
QT_MOC_LITERAL(115, 2060, 16), // "slotModifyOffset"
QT_MOC_LITERAL(116, 2077, 21), // "slotModifyExplodeText"
QT_MOC_LITERAL(117, 2099, 12), // "slotSetSnaps"
QT_MOC_LITERAL(118, 2112, 11), // "RS_SnapMode"
QT_MOC_LITERAL(119, 2124, 1), // "s"
QT_MOC_LITERAL(120, 2126, 12), // "slotSnapFree"
QT_MOC_LITERAL(121, 2139, 12), // "slotSnapGrid"
QT_MOC_LITERAL(122, 2152, 16), // "slotSnapEndpoint"
QT_MOC_LITERAL(123, 2169, 16), // "slotSnapOnEntity"
QT_MOC_LITERAL(124, 2186, 14), // "slotSnapCenter"
QT_MOC_LITERAL(125, 2201, 14), // "slotSnapMiddle"
QT_MOC_LITERAL(126, 2216, 12), // "slotSnapDist"
QT_MOC_LITERAL(127, 2229, 20), // "slotSnapIntersection"
QT_MOC_LITERAL(128, 2250, 26), // "slotSnapIntersectionManual"
QT_MOC_LITERAL(129, 2277, 19), // "slotRestrictNothing"
QT_MOC_LITERAL(130, 2297, 22), // "slotRestrictOrthogonal"
QT_MOC_LITERAL(131, 2320, 22), // "slotRestrictHorizontal"
QT_MOC_LITERAL(132, 2343, 20), // "slotRestrictVertical"
QT_MOC_LITERAL(133, 2364, 12), // "disableSnaps"
QT_MOC_LITERAL(134, 2377, 19), // "disableRestrictions"
QT_MOC_LITERAL(135, 2397, 19), // "slotSetRelativeZero"
QT_MOC_LITERAL(136, 2417, 20), // "slotLockRelativeZero"
QT_MOC_LITERAL(137, 2438, 2), // "on"
QT_MOC_LITERAL(138, 2441, 14), // "slotInfoInside"
QT_MOC_LITERAL(139, 2456, 12), // "slotInfoDist"
QT_MOC_LITERAL(140, 2469, 13), // "slotInfoDist2"
QT_MOC_LITERAL(141, 2483, 13), // "slotInfoAngle"
QT_MOC_LITERAL(142, 2497, 19), // "slotInfoTotalLength"
QT_MOC_LITERAL(143, 2517, 12), // "slotInfoArea"
QT_MOC_LITERAL(144, 2530, 21), // "slotLayersDefreezeAll"
QT_MOC_LITERAL(145, 2552, 19), // "slotLayersFreezeAll"
QT_MOC_LITERAL(146, 2572, 19), // "slotLayersUnlockAll"
QT_MOC_LITERAL(147, 2592, 17), // "slotLayersLockAll"
QT_MOC_LITERAL(148, 2610, 13), // "slotLayersAdd"
QT_MOC_LITERAL(149, 2624, 16), // "slotLayersRemove"
QT_MOC_LITERAL(150, 2641, 14), // "slotLayersEdit"
QT_MOC_LITERAL(151, 2656, 20), // "slotLayersToggleView"
QT_MOC_LITERAL(152, 2677, 20), // "slotLayersToggleLock"
QT_MOC_LITERAL(153, 2698, 21), // "slotLayersTogglePrint"
QT_MOC_LITERAL(154, 2720, 28), // "slotLayersToggleConstruction"
QT_MOC_LITERAL(155, 2749, 21), // "slotBlocksDefreezeAll"
QT_MOC_LITERAL(156, 2771, 19), // "slotBlocksFreezeAll"
QT_MOC_LITERAL(157, 2791, 13), // "slotBlocksAdd"
QT_MOC_LITERAL(158, 2805, 16), // "slotBlocksRemove"
QT_MOC_LITERAL(159, 2822, 20), // "slotBlocksAttributes"
QT_MOC_LITERAL(160, 2843, 14), // "slotBlocksEdit"
QT_MOC_LITERAL(161, 2858, 14), // "slotBlocksSave"
QT_MOC_LITERAL(162, 2873, 16), // "slotBlocksInsert"
QT_MOC_LITERAL(163, 2890, 20), // "slotBlocksToggleView"
QT_MOC_LITERAL(164, 2911, 16), // "slotBlocksCreate"
QT_MOC_LITERAL(165, 2928, 17), // "slotBlocksExplode"
QT_MOC_LITERAL(166, 2946, 18), // "slotOptionsDrawing"
QT_MOC_LITERAL(167, 2965, 16), // "toggleVisibility"
QT_MOC_LITERAL(168, 2982, 9), // "RS_Layer*"
QT_MOC_LITERAL(169, 2992, 5), // "layer"
QT_MOC_LITERAL(170, 2998, 10), // "toggleLock"
QT_MOC_LITERAL(171, 3009, 11), // "togglePrint"
QT_MOC_LITERAL(172, 3021, 18) // "toggleConstruction"

    },
    "QG_ActionHandler\0slotFileNewTemplate\0"
    "\0slotFileOpen\0slotFileSaveAs\0"
    "slotFileExportMakerCam\0slotZoomIn\0"
    "slotZoomOut\0slotZoomAuto\0slotZoomWindow\0"
    "slotZoomPan\0slotZoomPrevious\0"
    "slotZoomRedraw\0slotToolRegenerateDimensions\0"
    "slotEditKillAllActions\0slotEditUndo\0"
    "slotEditRedo\0slotEditCut\0slotEditCopy\0"
    "slotEditPaste\0slotOrderBottom\0"
    "slotOrderLower\0slotOrderRaise\0"
    "slotOrderTop\0slotSelectSingle\0"
    "slotSelectContour\0slotSelectWindow\0"
    "slotDeselectWindow\0slotSelectAll\0"
    "slotDeselectAll\0slotSelectInvert\0"
    "slotSelectIntersected\0slotDeselectIntersected\0"
    "slotSelectLayer\0slotDrawPoint\0"
    "slotDrawLine\0slotDrawLineAngle\0"
    "slotDrawLineHorizontal\0slotDrawLineVertical\0"
    "slotDrawLineFree\0slotDrawLineHorVert\0"
    "slotDrawLineParallel\0slotDrawLineParallelThrough\0"
    "slotDrawLineRectangle\0slotDrawLineBisector\0"
    "slotDrawLineTangent1\0slotDrawLineTangent2\0"
    "slotDrawLineOrthogonal\0slotDrawLineOrthTan\0"
    "slotDrawLineRelAngle\0slotDrawLinePolygon\0"
    "slotDrawLinePolygon2\0slotDrawLinePolygon3\0"
    "slotDrawCircle\0slotDrawCircleCR\0"
    "slotDrawCircle2P\0slotDrawCircle2PR\0"
    "slotDrawCircle3P\0slotDrawCircleParallel\0"
    "slotDrawCircleInscribe\0slotDrawCircleTan2\0"
    "slotDrawCircleTan3\0slotDrawCircleTan1_2P\0"
    "slotDrawCircleTan2_1P\0slotDrawArc\0"
    "slotDrawArc3P\0slotDrawArcParallel\0"
    "slotDrawArcTangential\0slotDrawEllipseAxis\0"
    "slotDrawEllipseArcAxis\0slotDrawEllipseFociPoint\0"
    "slotDrawEllipse4Points\0"
    "slotDrawEllipseCenter3Points\0"
    "slotDrawEllipseInscribe\0slotDrawSpline\0"
    "slotDrawSplinePoints\0slotDrawMText\0"
    "slotDrawText\0slotDrawHatch\0slotDrawImage\0"
    "slotDrawPolyline\0slotPolylineAdd\0"
    "slotPolylineAppend\0slotPolylineDel\0"
    "slotPolylineDelBetween\0slotPolylineTrim\0"
    "slotPolylineEquidistant\0slotPolylineSegment\0"
    "slotDimAligned\0slotDimLinear\0"
    "slotDimLinearHor\0slotDimLinearVer\0"
    "slotDimRadial\0slotDimDiametric\0"
    "slotDimAngular\0slotDimLeader\0"
    "slotModifyAttributes\0slotModifyDelete\0"
    "slotModifyDeleteQuick\0slotModifyDeleteFree\0"
    "slotModifyMove\0slotModifyScale\0"
    "slotModifyRevertDirection\0slotModifyRotate\0"
    "slotModifyMirror\0slotModifyMoveRotate\0"
    "slotModifyRotate2\0slotModifyEntity\0"
    "slotModifyTrim\0slotModifyTrim2\0"
    "slotModifyTrimAmount\0slotModifyCut\0"
    "slotModifyStretch\0slotModifyBevel\0"
    "slotModifyRound\0slotModifyOffset\0"
    "slotModifyExplodeText\0slotSetSnaps\0"
    "RS_SnapMode\0s\0slotSnapFree\0slotSnapGrid\0"
    "slotSnapEndpoint\0slotSnapOnEntity\0"
    "slotSnapCenter\0slotSnapMiddle\0"
    "slotSnapDist\0slotSnapIntersection\0"
    "slotSnapIntersectionManual\0"
    "slotRestrictNothing\0slotRestrictOrthogonal\0"
    "slotRestrictHorizontal\0slotRestrictVertical\0"
    "disableSnaps\0disableRestrictions\0"
    "slotSetRelativeZero\0slotLockRelativeZero\0"
    "on\0slotInfoInside\0slotInfoDist\0"
    "slotInfoDist2\0slotInfoAngle\0"
    "slotInfoTotalLength\0slotInfoArea\0"
    "slotLayersDefreezeAll\0slotLayersFreezeAll\0"
    "slotLayersUnlockAll\0slotLayersLockAll\0"
    "slotLayersAdd\0slotLayersRemove\0"
    "slotLayersEdit\0slotLayersToggleView\0"
    "slotLayersToggleLock\0slotLayersTogglePrint\0"
    "slotLayersToggleConstruction\0"
    "slotBlocksDefreezeAll\0slotBlocksFreezeAll\0"
    "slotBlocksAdd\0slotBlocksRemove\0"
    "slotBlocksAttributes\0slotBlocksEdit\0"
    "slotBlocksSave\0slotBlocksInsert\0"
    "slotBlocksToggleView\0slotBlocksCreate\0"
    "slotBlocksExplode\0slotOptionsDrawing\0"
    "toggleVisibility\0RS_Layer*\0layer\0"
    "toggleLock\0togglePrint\0toggleConstruction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QG_ActionHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     166,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  844,    2, 0x0a /* Public */,
       3,    0,  845,    2, 0x0a /* Public */,
       4,    0,  846,    2, 0x0a /* Public */,
       5,    0,  847,    2, 0x0a /* Public */,
       6,    0,  848,    2, 0x0a /* Public */,
       7,    0,  849,    2, 0x0a /* Public */,
       8,    0,  850,    2, 0x0a /* Public */,
       9,    0,  851,    2, 0x0a /* Public */,
      10,    0,  852,    2, 0x0a /* Public */,
      11,    0,  853,    2, 0x0a /* Public */,
      12,    0,  854,    2, 0x0a /* Public */,
      13,    0,  855,    2, 0x0a /* Public */,
      14,    0,  856,    2, 0x0a /* Public */,
      15,    0,  857,    2, 0x0a /* Public */,
      16,    0,  858,    2, 0x0a /* Public */,
      17,    0,  859,    2, 0x0a /* Public */,
      18,    0,  860,    2, 0x0a /* Public */,
      19,    0,  861,    2, 0x0a /* Public */,
      20,    0,  862,    2, 0x0a /* Public */,
      21,    0,  863,    2, 0x0a /* Public */,
      22,    0,  864,    2, 0x0a /* Public */,
      23,    0,  865,    2, 0x0a /* Public */,
      24,    0,  866,    2, 0x0a /* Public */,
      25,    0,  867,    2, 0x0a /* Public */,
      26,    0,  868,    2, 0x0a /* Public */,
      27,    0,  869,    2, 0x0a /* Public */,
      28,    0,  870,    2, 0x0a /* Public */,
      29,    0,  871,    2, 0x0a /* Public */,
      30,    0,  872,    2, 0x0a /* Public */,
      31,    0,  873,    2, 0x0a /* Public */,
      32,    0,  874,    2, 0x0a /* Public */,
      33,    0,  875,    2, 0x0a /* Public */,
      34,    0,  876,    2, 0x0a /* Public */,
      35,    0,  877,    2, 0x0a /* Public */,
      36,    0,  878,    2, 0x0a /* Public */,
      37,    0,  879,    2, 0x0a /* Public */,
      38,    0,  880,    2, 0x0a /* Public */,
      39,    0,  881,    2, 0x0a /* Public */,
      40,    0,  882,    2, 0x0a /* Public */,
      41,    0,  883,    2, 0x0a /* Public */,
      42,    0,  884,    2, 0x0a /* Public */,
      43,    0,  885,    2, 0x0a /* Public */,
      44,    0,  886,    2, 0x0a /* Public */,
      45,    0,  887,    2, 0x0a /* Public */,
      46,    0,  888,    2, 0x0a /* Public */,
      47,    0,  889,    2, 0x0a /* Public */,
      48,    0,  890,    2, 0x0a /* Public */,
      49,    0,  891,    2, 0x0a /* Public */,
      50,    0,  892,    2, 0x0a /* Public */,
      51,    0,  893,    2, 0x0a /* Public */,
      52,    0,  894,    2, 0x0a /* Public */,
      53,    0,  895,    2, 0x0a /* Public */,
      54,    0,  896,    2, 0x0a /* Public */,
      55,    0,  897,    2, 0x0a /* Public */,
      56,    0,  898,    2, 0x0a /* Public */,
      57,    0,  899,    2, 0x0a /* Public */,
      58,    0,  900,    2, 0x0a /* Public */,
      59,    0,  901,    2, 0x0a /* Public */,
      60,    0,  902,    2, 0x0a /* Public */,
      61,    0,  903,    2, 0x0a /* Public */,
      62,    0,  904,    2, 0x0a /* Public */,
      63,    0,  905,    2, 0x0a /* Public */,
      64,    0,  906,    2, 0x0a /* Public */,
      65,    0,  907,    2, 0x0a /* Public */,
      66,    0,  908,    2, 0x0a /* Public */,
      67,    0,  909,    2, 0x0a /* Public */,
      68,    0,  910,    2, 0x0a /* Public */,
      69,    0,  911,    2, 0x0a /* Public */,
      70,    0,  912,    2, 0x0a /* Public */,
      71,    0,  913,    2, 0x0a /* Public */,
      72,    0,  914,    2, 0x0a /* Public */,
      73,    0,  915,    2, 0x0a /* Public */,
      74,    0,  916,    2, 0x0a /* Public */,
      75,    0,  917,    2, 0x0a /* Public */,
      76,    0,  918,    2, 0x0a /* Public */,
      77,    0,  919,    2, 0x0a /* Public */,
      78,    0,  920,    2, 0x0a /* Public */,
      79,    0,  921,    2, 0x0a /* Public */,
      80,    0,  922,    2, 0x0a /* Public */,
      81,    0,  923,    2, 0x0a /* Public */,
      82,    0,  924,    2, 0x0a /* Public */,
      83,    0,  925,    2, 0x0a /* Public */,
      84,    0,  926,    2, 0x0a /* Public */,
      85,    0,  927,    2, 0x0a /* Public */,
      86,    0,  928,    2, 0x0a /* Public */,
      87,    0,  929,    2, 0x0a /* Public */,
      88,    0,  930,    2, 0x0a /* Public */,
      89,    0,  931,    2, 0x0a /* Public */,
      90,    0,  932,    2, 0x0a /* Public */,
      91,    0,  933,    2, 0x0a /* Public */,
      92,    0,  934,    2, 0x0a /* Public */,
      93,    0,  935,    2, 0x0a /* Public */,
      94,    0,  936,    2, 0x0a /* Public */,
      95,    0,  937,    2, 0x0a /* Public */,
      96,    0,  938,    2, 0x0a /* Public */,
      97,    0,  939,    2, 0x0a /* Public */,
      98,    0,  940,    2, 0x0a /* Public */,
      99,    0,  941,    2, 0x0a /* Public */,
     100,    0,  942,    2, 0x0a /* Public */,
     101,    0,  943,    2, 0x0a /* Public */,
     102,    0,  944,    2, 0x0a /* Public */,
     103,    0,  945,    2, 0x0a /* Public */,
     104,    0,  946,    2, 0x0a /* Public */,
     105,    0,  947,    2, 0x0a /* Public */,
     106,    0,  948,    2, 0x0a /* Public */,
     107,    0,  949,    2, 0x0a /* Public */,
     108,    0,  950,    2, 0x0a /* Public */,
     109,    0,  951,    2, 0x0a /* Public */,
     110,    0,  952,    2, 0x0a /* Public */,
     111,    0,  953,    2, 0x0a /* Public */,
     112,    0,  954,    2, 0x0a /* Public */,
     113,    0,  955,    2, 0x0a /* Public */,
     114,    0,  956,    2, 0x0a /* Public */,
     115,    0,  957,    2, 0x0a /* Public */,
     116,    0,  958,    2, 0x0a /* Public */,
     117,    1,  959,    2, 0x0a /* Public */,
     120,    0,  962,    2, 0x0a /* Public */,
     121,    0,  963,    2, 0x0a /* Public */,
     122,    0,  964,    2, 0x0a /* Public */,
     123,    0,  965,    2, 0x0a /* Public */,
     124,    0,  966,    2, 0x0a /* Public */,
     125,    0,  967,    2, 0x0a /* Public */,
     126,    0,  968,    2, 0x0a /* Public */,
     127,    0,  969,    2, 0x0a /* Public */,
     128,    0,  970,    2, 0x0a /* Public */,
     129,    0,  971,    2, 0x0a /* Public */,
     130,    0,  972,    2, 0x0a /* Public */,
     131,    0,  973,    2, 0x0a /* Public */,
     132,    0,  974,    2, 0x0a /* Public */,
     133,    0,  975,    2, 0x0a /* Public */,
     134,    0,  976,    2, 0x0a /* Public */,
     135,    0,  977,    2, 0x0a /* Public */,
     136,    1,  978,    2, 0x0a /* Public */,
     138,    0,  981,    2, 0x0a /* Public */,
     139,    0,  982,    2, 0x0a /* Public */,
     140,    0,  983,    2, 0x0a /* Public */,
     141,    0,  984,    2, 0x0a /* Public */,
     142,    0,  985,    2, 0x0a /* Public */,
     143,    0,  986,    2, 0x0a /* Public */,
     144,    0,  987,    2, 0x0a /* Public */,
     145,    0,  988,    2, 0x0a /* Public */,
     146,    0,  989,    2, 0x0a /* Public */,
     147,    0,  990,    2, 0x0a /* Public */,
     148,    0,  991,    2, 0x0a /* Public */,
     149,    0,  992,    2, 0x0a /* Public */,
     150,    0,  993,    2, 0x0a /* Public */,
     151,    0,  994,    2, 0x0a /* Public */,
     152,    0,  995,    2, 0x0a /* Public */,
     153,    0,  996,    2, 0x0a /* Public */,
     154,    0,  997,    2, 0x0a /* Public */,
     155,    0,  998,    2, 0x0a /* Public */,
     156,    0,  999,    2, 0x0a /* Public */,
     157,    0, 1000,    2, 0x0a /* Public */,
     158,    0, 1001,    2, 0x0a /* Public */,
     159,    0, 1002,    2, 0x0a /* Public */,
     160,    0, 1003,    2, 0x0a /* Public */,
     161,    0, 1004,    2, 0x0a /* Public */,
     162,    0, 1005,    2, 0x0a /* Public */,
     163,    0, 1006,    2, 0x0a /* Public */,
     164,    0, 1007,    2, 0x0a /* Public */,
     165,    0, 1008,    2, 0x0a /* Public */,
     166,    0, 1009,    2, 0x0a /* Public */,
     167,    1, 1010,    2, 0x0a /* Public */,
     170,    1, 1013,    2, 0x0a /* Public */,
     171,    1, 1016,    2, 0x0a /* Public */,
     172,    1, 1019,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 118,  119,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  137,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 168,  169,
    QMetaType::Void, 0x80000000 | 168,  169,
    QMetaType::Void, 0x80000000 | 168,  169,
    QMetaType::Void, 0x80000000 | 168,  169,

       0        // eod
};

void QG_ActionHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QG_ActionHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotFileNewTemplate(); break;
        case 1: _t->slotFileOpen(); break;
        case 2: _t->slotFileSaveAs(); break;
        case 3: _t->slotFileExportMakerCam(); break;
        case 4: _t->slotZoomIn(); break;
        case 5: _t->slotZoomOut(); break;
        case 6: _t->slotZoomAuto(); break;
        case 7: _t->slotZoomWindow(); break;
        case 8: _t->slotZoomPan(); break;
        case 9: _t->slotZoomPrevious(); break;
        case 10: _t->slotZoomRedraw(); break;
        case 11: _t->slotToolRegenerateDimensions(); break;
        case 12: _t->slotEditKillAllActions(); break;
        case 13: _t->slotEditUndo(); break;
        case 14: _t->slotEditRedo(); break;
        case 15: _t->slotEditCut(); break;
        case 16: _t->slotEditCopy(); break;
        case 17: _t->slotEditPaste(); break;
        case 18: _t->slotOrderBottom(); break;
        case 19: _t->slotOrderLower(); break;
        case 20: _t->slotOrderRaise(); break;
        case 21: _t->slotOrderTop(); break;
        case 22: _t->slotSelectSingle(); break;
        case 23: _t->slotSelectContour(); break;
        case 24: _t->slotSelectWindow(); break;
        case 25: _t->slotDeselectWindow(); break;
        case 26: _t->slotSelectAll(); break;
        case 27: _t->slotDeselectAll(); break;
        case 28: _t->slotSelectInvert(); break;
        case 29: _t->slotSelectIntersected(); break;
        case 30: _t->slotDeselectIntersected(); break;
        case 31: _t->slotSelectLayer(); break;
        case 32: _t->slotDrawPoint(); break;
        case 33: _t->slotDrawLine(); break;
        case 34: _t->slotDrawLineAngle(); break;
        case 35: _t->slotDrawLineHorizontal(); break;
        case 36: _t->slotDrawLineVertical(); break;
        case 37: _t->slotDrawLineFree(); break;
        case 38: _t->slotDrawLineHorVert(); break;
        case 39: _t->slotDrawLineParallel(); break;
        case 40: _t->slotDrawLineParallelThrough(); break;
        case 41: _t->slotDrawLineRectangle(); break;
        case 42: _t->slotDrawLineBisector(); break;
        case 43: _t->slotDrawLineTangent1(); break;
        case 44: _t->slotDrawLineTangent2(); break;
        case 45: _t->slotDrawLineOrthogonal(); break;
        case 46: _t->slotDrawLineOrthTan(); break;
        case 47: _t->slotDrawLineRelAngle(); break;
        case 48: _t->slotDrawLinePolygon(); break;
        case 49: _t->slotDrawLinePolygon2(); break;
        case 50: _t->slotDrawLinePolygon3(); break;
        case 51: _t->slotDrawCircle(); break;
        case 52: _t->slotDrawCircleCR(); break;
        case 53: _t->slotDrawCircle2P(); break;
        case 54: _t->slotDrawCircle2PR(); break;
        case 55: _t->slotDrawCircle3P(); break;
        case 56: _t->slotDrawCircleParallel(); break;
        case 57: _t->slotDrawCircleInscribe(); break;
        case 58: _t->slotDrawCircleTan2(); break;
        case 59: _t->slotDrawCircleTan3(); break;
        case 60: _t->slotDrawCircleTan1_2P(); break;
        case 61: _t->slotDrawCircleTan2_1P(); break;
        case 62: _t->slotDrawArc(); break;
        case 63: _t->slotDrawArc3P(); break;
        case 64: _t->slotDrawArcParallel(); break;
        case 65: _t->slotDrawArcTangential(); break;
        case 66: _t->slotDrawEllipseAxis(); break;
        case 67: _t->slotDrawEllipseArcAxis(); break;
        case 68: _t->slotDrawEllipseFociPoint(); break;
        case 69: _t->slotDrawEllipse4Points(); break;
        case 70: _t->slotDrawEllipseCenter3Points(); break;
        case 71: _t->slotDrawEllipseInscribe(); break;
        case 72: _t->slotDrawSpline(); break;
        case 73: _t->slotDrawSplinePoints(); break;
        case 74: _t->slotDrawMText(); break;
        case 75: _t->slotDrawText(); break;
        case 76: _t->slotDrawHatch(); break;
        case 77: _t->slotDrawImage(); break;
        case 78: _t->slotDrawPolyline(); break;
        case 79: _t->slotPolylineAdd(); break;
        case 80: _t->slotPolylineAppend(); break;
        case 81: _t->slotPolylineDel(); break;
        case 82: _t->slotPolylineDelBetween(); break;
        case 83: _t->slotPolylineTrim(); break;
        case 84: _t->slotPolylineEquidistant(); break;
        case 85: _t->slotPolylineSegment(); break;
        case 86: _t->slotDimAligned(); break;
        case 87: _t->slotDimLinear(); break;
        case 88: _t->slotDimLinearHor(); break;
        case 89: _t->slotDimLinearVer(); break;
        case 90: _t->slotDimRadial(); break;
        case 91: _t->slotDimDiametric(); break;
        case 92: _t->slotDimAngular(); break;
        case 93: _t->slotDimLeader(); break;
        case 94: _t->slotModifyAttributes(); break;
        case 95: _t->slotModifyDelete(); break;
        case 96: _t->slotModifyDeleteQuick(); break;
        case 97: _t->slotModifyDeleteFree(); break;
        case 98: _t->slotModifyMove(); break;
        case 99: _t->slotModifyScale(); break;
        case 100: _t->slotModifyRevertDirection(); break;
        case 101: _t->slotModifyRotate(); break;
        case 102: _t->slotModifyMirror(); break;
        case 103: _t->slotModifyMoveRotate(); break;
        case 104: _t->slotModifyRotate2(); break;
        case 105: _t->slotModifyEntity(); break;
        case 106: _t->slotModifyTrim(); break;
        case 107: _t->slotModifyTrim2(); break;
        case 108: _t->slotModifyTrimAmount(); break;
        case 109: _t->slotModifyCut(); break;
        case 110: _t->slotModifyStretch(); break;
        case 111: _t->slotModifyBevel(); break;
        case 112: _t->slotModifyRound(); break;
        case 113: _t->slotModifyOffset(); break;
        case 114: _t->slotModifyExplodeText(); break;
        case 115: _t->slotSetSnaps((*reinterpret_cast< const RS_SnapMode(*)>(_a[1]))); break;
        case 116: _t->slotSnapFree(); break;
        case 117: _t->slotSnapGrid(); break;
        case 118: _t->slotSnapEndpoint(); break;
        case 119: _t->slotSnapOnEntity(); break;
        case 120: _t->slotSnapCenter(); break;
        case 121: _t->slotSnapMiddle(); break;
        case 122: _t->slotSnapDist(); break;
        case 123: _t->slotSnapIntersection(); break;
        case 124: _t->slotSnapIntersectionManual(); break;
        case 125: _t->slotRestrictNothing(); break;
        case 126: _t->slotRestrictOrthogonal(); break;
        case 127: _t->slotRestrictHorizontal(); break;
        case 128: _t->slotRestrictVertical(); break;
        case 129: _t->disableSnaps(); break;
        case 130: _t->disableRestrictions(); break;
        case 131: _t->slotSetRelativeZero(); break;
        case 132: _t->slotLockRelativeZero((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 133: _t->slotInfoInside(); break;
        case 134: _t->slotInfoDist(); break;
        case 135: _t->slotInfoDist2(); break;
        case 136: _t->slotInfoAngle(); break;
        case 137: _t->slotInfoTotalLength(); break;
        case 138: _t->slotInfoArea(); break;
        case 139: _t->slotLayersDefreezeAll(); break;
        case 140: _t->slotLayersFreezeAll(); break;
        case 141: _t->slotLayersUnlockAll(); break;
        case 142: _t->slotLayersLockAll(); break;
        case 143: _t->slotLayersAdd(); break;
        case 144: _t->slotLayersRemove(); break;
        case 145: _t->slotLayersEdit(); break;
        case 146: _t->slotLayersToggleView(); break;
        case 147: _t->slotLayersToggleLock(); break;
        case 148: _t->slotLayersTogglePrint(); break;
        case 149: _t->slotLayersToggleConstruction(); break;
        case 150: _t->slotBlocksDefreezeAll(); break;
        case 151: _t->slotBlocksFreezeAll(); break;
        case 152: _t->slotBlocksAdd(); break;
        case 153: _t->slotBlocksRemove(); break;
        case 154: _t->slotBlocksAttributes(); break;
        case 155: _t->slotBlocksEdit(); break;
        case 156: _t->slotBlocksSave(); break;
        case 157: _t->slotBlocksInsert(); break;
        case 158: _t->slotBlocksToggleView(); break;
        case 159: _t->slotBlocksCreate(); break;
        case 160: _t->slotBlocksExplode(); break;
        case 161: _t->slotOptionsDrawing(); break;
        case 162: _t->toggleVisibility((*reinterpret_cast< RS_Layer*(*)>(_a[1]))); break;
        case 163: _t->toggleLock((*reinterpret_cast< RS_Layer*(*)>(_a[1]))); break;
        case 164: _t->togglePrint((*reinterpret_cast< RS_Layer*(*)>(_a[1]))); break;
        case 165: _t->toggleConstruction((*reinterpret_cast< RS_Layer*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QG_ActionHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QG_ActionHandler.data,
    qt_meta_data_QG_ActionHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QG_ActionHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QG_ActionHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QG_ActionHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QG_ActionHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 166)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 166;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 166)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 166;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
