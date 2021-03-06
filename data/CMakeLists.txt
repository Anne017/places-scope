find_program(INTLTOOL_MERGE intltool-merge)
set(PLACES_INI_TARGET com.ubuntu.developer.labsin.places_places.ini)
set(PLACES_SETTINGS_TARGET com.ubuntu.developer.labsin.places_places-settings.ini)

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/src/${PLACES_INI_TARGET}
    COMMENT "Merging translations into ${PLACES_INI_TARGET}"
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${PLACES_INI_TARGET}.in ${PLACES_INI_TARGET}.in
    COMMAND LC_ALL=C ${INTLTOOL_MERGE} -d -u ${CMAKE_SOURCE_DIR}/po ${PLACES_INI_TARGET}.in ${PLACES_INI_TARGET} >/dev/null
    COMMAND ${CMAKE_COMMAND} -E remove ${PLACES_INI_TARGET}.in
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src
)

add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/src/${PLACES_SETTINGS_TARGET}
    COMMENT "Merging translations into ${PLACES_SETTINGS_TARGET}"
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${PLACES_SETTINGS_TARGET}.in ${PLACES_SETTINGS_TARGET}.in
    COMMAND LC_ALL=C ${INTLTOOL_MERGE} -d -u ${CMAKE_SOURCE_DIR}/po ${PLACES_SETTINGS_TARGET}.in ${PLACES_SETTINGS_TARGET} >/dev/null
    COMMAND ${CMAKE_COMMAND} -E remove ${PLACES_SETTINGS_TARGET}.in
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src
)

add_custom_target(
    merge_init ALL
    DEPENDS ${CMAKE_SOURCE_DIR}/po/*.po ${CMAKE_BINARY_DIR}/src/${PLACES_INI_TARGET} ${CMAKE_BINARY_DIR}/src/${PLACES_SETTINGS_TARGET}
)

add_dependencies(merge_init pot)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/logo.png"
    "${CMAKE_BINARY_DIR}/src/logo.png"
    @ONLY
    COPYONLY
)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/places.jpg"
    "${CMAKE_BINARY_DIR}/src/places.jpg"
    @ONLY
    COPYONLY
)

set(FILES_TO_SHOW
    "com.ubuntu.developer.labsin.places_places.ini.in"
    "com.ubuntu.developer.labsin.places_places-settings.ini.in"
    "icon.png"
    "icon_512x512.png"
    "logo.png"
    "places.jpg"
    "screenshot.png"
)

qtcreator_add_project_resources(${FILES_TO_SHOW})

# Install the scope ini file
install(
  FILES ${CMAKE_BINARY_DIR}/src/${PLACES_INI_TARGET}
        ${CMAKE_BINARY_DIR}/src/${PLACES_SETTINGS_TARGET}
  DESTINATION ${SCOPE_INSTALL_DIR}
)

# Install the scope images
install(
  FILES
    "icon.png"
    "icon_512x512.png"
    "logo.png"
    "places.jpg"
    "screenshot.png"
  DESTINATION
    "${SCOPE_INSTALL_DIR}"
)

