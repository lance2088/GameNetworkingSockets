//====== Copyright Valve Corporation, All rights reserved. ====================
//
// Plain C interface to SteamNetworkingSockets
//
// Designed to match the auto-generated flat interface in the Steamworks SDK
// (for better or worse...)
//
//=============================================================================

#ifndef STEAMNETWORKINGSOCKETS_FLAT
#define STEAMNETWORKINGSOCKETS_FLAT
#pragma once

#include <stdint.h>
#include "steamnetworkingtypes.h"

extern "C" {

STEAMNETWORKINGSOCKETS_INTERFACE HSteamListenSocket SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP( intptr_t instancePtr, const SteamNetworkingIPAddr *pAddress );
STEAMNETWORKINGSOCKETS_INTERFACE HSteamNetConnection SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress( intptr_t instancePtr, const SteamNetworkingIPAddr *pAddress );
#ifndef STEAMNETWORKINGSOCKETS_OPENSOURCE
STEAMNETWORKINGSOCKETS_INTERFACE HSteamNetConnection SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P( intptr_t instancePtr, int nVirtualPort );
STEAMNETWORKINGSOCKETS_INTERFACE HSteamNetConnection SteamAPI_ISteamNetworkingSockets_ConnectP2P( intptr_t instancePtr, const SteamNetworkingIdentity *pIdentity, int nVirtualPort );
#endif
STEAMNETWORKINGSOCKETS_INTERFACE EResult SteamAPI_ISteamNetworkingSockets_AcceptConnection( intptr_t instancePtr, HSteamNetConnection hConn );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_CloseConnection( intptr_t instancePtr, HSteamNetConnection hPeer, int nReason, const char *pszDebug, bool bEnableLinger );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_CloseListenSocket( intptr_t instancePtr, HSteamListenSocket hSocket );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_SetConnectionUserData( intptr_t instancePtr, HSteamNetConnection hPeer, int64 nUserData );
STEAMNETWORKINGSOCKETS_INTERFACE int64 SteamAPI_ISteamNetworkingSockets_GetConnectionUserData( intptr_t instancePtr, HSteamNetConnection hPeer );
STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_ISteamNetworkingSockets_SetConnectionName( intptr_t instancePtr, HSteamNetConnection hPeer, const char *pszName );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetConnectionName( intptr_t instancePtr, HSteamNetConnection hPeer, char *pszName, int nMaxLen );
STEAMNETWORKINGSOCKETS_INTERFACE EResult SteamAPI_ISteamNetworkingSockets_SendMessageToConnection( intptr_t instancePtr, HSteamNetConnection hConn, const void *pData, uint32 cbData, ESteamNetworkingSendType eSendType );
STEAMNETWORKINGSOCKETS_INTERFACE EResult SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection( intptr_t instancePtr, HSteamNetConnection hConn );
STEAMNETWORKINGSOCKETS_INTERFACE int SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection( intptr_t instancePtr, HSteamNetConnection hConn, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages ); 
STEAMNETWORKINGSOCKETS_INTERFACE int SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnListenSocket( intptr_t instancePtr, HSteamListenSocket hSocket, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages ); 
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetConnectionInfo( intptr_t instancePtr, HSteamNetConnection hConn, SteamNetConnectionInfo_t *pInfo );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetQuickConnectionStatus( intptr_t instancePtr, HSteamNetConnection hConn, SteamNetworkingQuickConnectionStatus *pStats );
STEAMNETWORKINGSOCKETS_INTERFACE int SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus( intptr_t instancePtr, HSteamNetConnection hConn, char *pszBuf, int cbBuf );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress( intptr_t instancePtr, HSteamListenSocket hSocket, SteamNetworkingIPAddr *pAddress );

STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_CreateSocketPair( intptr_t instancePtr, HSteamNetConnection *pOutConnection1, HSteamNetConnection *pOutConnection2, bool bUseNetworkLoopback, const SteamNetworkingIdentity *pIdentity1, const SteamNetworkingIdentity *pIdentity2 );

#ifndef STEAMNETWORKINGSOCKETS_OPENSOURCE

STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket( intptr_t instancePtr, const void *pvTicket, int cbTicket, SteamDatagramRelayAuthTicket *pOutParsedTicket );
STEAMNETWORKINGSOCKETS_INTERFACE int SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer( intptr_t instancePtr, const SteamNetworkingIdentity *pIdentityGameserver, int nVirtualPort, SteamDatagramRelayAuthTicket *pOutParsedTicket );
STEAMNETWORKINGSOCKETS_INTERFACE HSteamNetConnection SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer( intptr_t instancePtr, const SteamNetworkingIdentity *pIdentityTarget, int nVirtualPort );
STEAMNETWORKINGSOCKETS_INTERFACE uint16 SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort( intptr_t instancePtr );
STEAMNETWORKINGSOCKETS_INTERFACE SteamNetworkingPOPID SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID( intptr_t instancePtr );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress( intptr_t instancePtr, SteamDatagramHostedAddress *pRouting );
STEAMNETWORKINGSOCKETS_INTERFACE HSteamListenSocket SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket( intptr_t instancePtr, int nVirtualPort );

#endif // #ifndef STEAMNETWORKINGSOCKETS_OPENSOURCE

STEAMNETWORKINGSOCKETS_INTERFACE int32 SteamAPI_ISteamNetworkingSockets_GetConfigurationValue( intptr_t instancePtr, ESteamNetworkingConfigurationValue eConfigValue );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_SetConfigurationValue( intptr_t instancePtr, ESteamNetworkingConfigurationValue eConfigValue, int32 nValue );
STEAMNETWORKINGSOCKETS_INTERFACE const char *SteamAPI_ISteamNetworkingSockets_GetConfigurationValueName( intptr_t instancePtr, ESteamNetworkingConfigurationValue eConfigValue );
STEAMNETWORKINGSOCKETS_INTERFACE int32 SteamAPI_ISteamNetworkingSockets_GetConfigurationString( intptr_t instancePtr, ESteamNetworkingConfigurationString eConfigString, char *pDest, int32 destSize );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_SetConfigurationString( intptr_t instancePtr, ESteamNetworkingConfigurationString eConfigString, const char *pString );
STEAMNETWORKINGSOCKETS_INTERFACE const char *SteamAPI_ISteamNetworkingSockets_GetConfigurationStringName( intptr_t instancePtr, ESteamNetworkingConfigurationString eConfigString );
STEAMNETWORKINGSOCKETS_INTERFACE int32 SteamAPI_ISteamNetworkingSockets_GetConnectionConfigurationValue( intptr_t instancePtr, HSteamNetConnection hConn, ESteamNetworkingConnectionConfigurationValue eConfigValue );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_ISteamNetworkingSockets_SetConnectionConfigurationValue( intptr_t instancePtr, HSteamNetConnection hConn, ESteamNetworkingConnectionConfigurationValue eConfigValue, int32 nValue );

STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_SteamNetworkingMessage_t_Release( SteamNetworkingMessage_t *pMsg );

STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_SteamNetworkingIPAddr_Clear( SteamNetworkingIPAddr *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros( const SteamNetworkingIPAddr *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_SteamNetworkingIPAddr_SetIPv6( SteamNetworkingIPAddr *pThis, const uint8 *ipv6, uint16 nPort );
STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_SteamNetworkingIPAddr_SetIPv4( SteamNetworkingIPAddr *pThis, uint32 nIP, uint16 nPort );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_SteamNetworkingIPAddr_IsIPv4( const SteamNetworkingIPAddr *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE uint32 SteamAPI_SteamNetworkingIPAddr_GetIPv4( const SteamNetworkingIPAddr *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost( SteamNetworkingIPAddr *pThis, uint16 nPort );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_SteamNetworkingIPAddr_IsLocalHost( const SteamNetworkingIPAddr *pThis );
// Note: in steamnetworkingtypes.h:
// SteamAPI_SteamNetworkingIPAddr_ToString
// SteamAPI_SteamNetworkingIPAddr_ParseString

STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_SteamNetworkingIdentity_Clear( SteamNetworkingIdentity *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_SteamNetworkingIdentity_IsInvalid( const SteamNetworkingIdentity *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_SteamNetworkingIdentity_SetSteamID64( SteamNetworkingIdentity *pThis, uint64 steamID );
STEAMNETWORKINGSOCKETS_INTERFACE uint64 SteamAPI_SteamNetworkingIdentity_GetSteamID64( const SteamNetworkingIdentity *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_SteamNetworkingIdentity_SetIPAddr( SteamNetworkingIdentity *pThis, const SteamNetworkingIPAddr *pAddr );
STEAMNETWORKINGSOCKETS_INTERFACE const SteamNetworkingIPAddr *SteamAPI_SteamNetworkingIdentity_GetIPAddr( SteamNetworkingIdentity *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_SteamNetworkingIdentity_SetLocalHost( SteamNetworkingIdentity *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_SteamNetworkingIdentity_IsLocalHost( const SteamNetworkingIdentity *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_SteamNetworkingIdentity_SetGenericString( SteamNetworkingIdentity *pThis, const char *pszString );
STEAMNETWORKINGSOCKETS_INTERFACE const char *SteamAPI_SteamNetworkingIdentity_GetGenericString( const SteamNetworkingIdentity *pThis );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_SteamNetworkingIdentity_SetGenericBytes( SteamNetworkingIdentity *pThis, const void *data, size_t cbLen );
STEAMNETWORKINGSOCKETS_INTERFACE const uint8 *SteamAPI_SteamNetworkingIdentity_GetGenericBytes( const SteamNetworkingIdentity *pThis, int *pOutLen );
STEAMNETWORKINGSOCKETS_INTERFACE bool SteamAPI_SteamNetworkingIdentity_EqualTo( const SteamNetworkingIdentity *a, const SteamNetworkingIdentity *b );
STEAMNETWORKINGSOCKETS_INTERFACE uint32 SteamAPI_SteamNetworkingIdentity_Hash( const SteamNetworkingIdentity *pThis );
// Note: in steamnetworkingtypes.h
// SteamAPI_SteamNetworkingIdentity_ToString
// SteamAPI_SteamNetworkingIdentity_ParseString

// Temporarily callback dispatch mechanism.  Eventually in Steamworks
// this function won't exist, the callbacks will be dispatched through the
// SteamAPI_RunCallbacks method, and this will only be used in the opensource
// version.
typedef void (*FSteamNetConnectionStatusChangedCallback)( SteamNetConnectionStatusChangedCallback_t *pInfo, intptr_t context );
STEAMNETWORKINGSOCKETS_INTERFACE void SteamAPI_ISteamNetworkingSockets_RunConnectionStatusChangedCallbacks ( intptr_t instancePtr, FSteamNetConnectionStatusChangedCallback callback, intptr_t context );

}

#endif // ISTEAMNETWORKINGSOCKETS
